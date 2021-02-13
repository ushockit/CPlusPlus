#include <iostream>
#include <list>

using namespace std;



int main() {

	list<int> lst, lst2;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);

	// добавление списк в конец
	//lst.splice(lst.end(), lst2);
	lst.splice(++lst.begin(), lst2);


	auto it = lst.begin();

	while (it != lst.end()) {
		cout << (*it) << " ";
		it++;
	}
	cout << endl;

	return 0;
}