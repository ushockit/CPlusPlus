#include <iostream>
#include <vector>
using namespace std;


int randNum(int from, int to) {
	return rand() % (to - from) + from;
}

void fill(vector<int>& vals, int from, int to, int count) {
	for (int i = 0; i < count; i++) {
		vals.push_back(randNum(from ,to));
	}
}

void print(const vector<int>& vals) {
	/*for (int i = 0; i < vals.size(); i++)
	{
		cout << vals[i] << " ";
	}
	cout << endl;*/
	//vector<int>::const_iterator it = vals.begin();
	auto it = vals.begin();

	while (it != vals.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl << "-----------------" << endl;
}

int main() {

	// STL - Standard Template Library

	/*vector<int> nums;

	fill(nums, 0, 50, 15);
	print(nums);

	//вставка в начало
	nums.insert(nums.begin(), 100);
	print(nums);

	//вставка на 3ю позицию
	nums.insert(nums.begin() + 2, 200);
	print(nums);

	//удаление 2го элемента
	nums.erase(nums.begin() + 1);
	print(nums);

	//удаление последнего эл-та
	nums.erase(nums.end() - 1);
	print(nums);


	//очистка
	nums.clear();

	if (nums.empty()) {
		cout << "Vector is empty" << endl;
	}*/


	//Вложенные вектора
	/*vector<vector<int>> dArr;

	for (int i = 0; i < 10; i++) {
		vector<int> v;
		fill(v, 0, 100, randNum(5, 10));
		dArr.push_back(v);
	}

	dArr[5].push_back(100);
	dArr[5].push_back(200);


	auto it = dArr.begin();
	while (it != dArr.end()) {
		auto it2 = (*it).begin();
		while (it2 != (*it).end()) {
			cout << (*it2) << " ";
			it2++;
		}
		it++;
		cout << endl;
	}*/





	return 0;
}