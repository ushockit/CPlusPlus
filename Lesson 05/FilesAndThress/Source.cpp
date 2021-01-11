#include <iostream>
#include "Tree.h"
using namespace std;




int main() {
	Tree tree;

	//заполнение дерева
	tree.insert(100);
	tree.insert(50);
	tree.insert(90);
	tree.insert(88);
	tree.insert(11);
	tree.insert(7);
	tree.insert(-10);
	tree.insert(13);
	tree.insert(222);
	tree.insert(136);
	tree.insert(356);


	/*Leaf* min = tree.min();
	Leaf* max = tree.max();

	cout << "Min element = " << min->value << endl;
	cout << "Max element = " << max->value << endl;*/
	
	//вывод дерева
	//tree.print(tree.getRoot());

	/*Leaf* srch = tree.search(tree.getRoot(), 11);

	if (srch) {
		//cout << srch->value << endl;
		tree.print(srch);
	}
	else {
		cout << "Not found" << endl;
	}*/

	system("pause");
	return 0;
}