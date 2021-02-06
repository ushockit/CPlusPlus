#include <iostream>

using namespace std;


namespace A {
	class File {
		string filename;
		string extension;
		long size;
	public:
		File(string path) {
			filename = "some filename from path";
			extension = "some extension from path";
			size = 1068;
		}
	};
	void demo() {
		cout << "demo from namespace A" << endl;
	}
}

namespace B {
	class File {
		File() {}
	public:
		static string readAllText() { return string(); }
		static string* readAllLines() { return nullptr; }
	};
	void demo() {
		cout << "demo from namespace B" << endl;
	}
}

//using namespace A;
//using namespace B;

int main() {

	// -= Пространства имен =-

	//A::demo();
	//B::demo();
	//A::File file("C:\\Program Files\\demo.txt");
	//B::File::readAllText();

	return 0;
}