#include <iostream>
#include <fstream>


using namespace std;


class BaseFileHelper {
protected:
	string path;
public:
	BaseFileHelper(string path) : path(path) {}

	virtual void write(string data) = 0;
	virtual string read() = 0;
};


class TextFileHelper : public BaseFileHelper {
public:
	TextFileHelper(string path) : BaseFileHelper(path) {}
	// Inherited via AbstractFileHelper
	virtual void write(string data) override
	{
		ofstream out(path, ios::binary);

		if (out.is_open()) {
			out.write(data.c_str(), data.size());
			out.close();
		}
	}
	virtual string read() override
	{
		string data;
		ifstream in(path, ios::binary);
		if (in.is_open()) {
			in >> data;
			in.close();
		}
		return data;
	}
};

class EncodeFileHelper : public BaseFileHelper {
public:
	EncodeFileHelper(string path) : BaseFileHelper(path) {}
	virtual void write(string data) override
	{
		string result;
		for (int i = 0; i < data.size(); i++)
		{
			char symb = data[i] ^ 7;
			result.push_back(symb);
		}
		ofstream out(path, ios::binary);

		if (out.is_open()) {
			out.write(result.c_str(), result.size());
			out.close();
		}
	}

	virtual string read() override
	{
		string data;
		ifstream in(path, ios::binary);
		if (in.is_open()) {
			in >> data;
			in.close();
		}

		string result;
		for (int i = 0; i < data.size(); i++)
		{
			result.push_back(data[i] ^ 7);
		}
		return result;
	}
};

int main() {

	BaseFileHelper* fileHelper = new EncodeFileHelper("demo.bin");




	while (true) {
		system("cls");
		int action;

		cout << "[1] Write" << endl;
		cout << "[2] Read" << endl;
		cin >> action;


		switch (action) {
		case 1: {
			string tmp;
			cin >> tmp;
			fileHelper->write(tmp);
			break;
		}
		case 2: {
			string result = fileHelper->read();
			cout << result << endl;
			break;
		}
		}
		system("pause");
	}

	return 0;
}