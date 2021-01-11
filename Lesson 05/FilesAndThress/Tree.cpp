#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	//очистка дерева относительно корня
	clear(root);
	system("pause");
}

void Tree::print(const Leaf* leaf)
{
	//узел существует
	if (leaf) {
		print(leaf->left);
		std::cout << leaf->value << std::endl;
		print(leaf->right);
	}
}

Leaf* Tree::min()
{
	if (!root) {
		return nullptr;
	}
	//узел для прохода по дереву
	Leaf* tmp = root;

	//спускаемся по левой ветке в самый низ
	while (tmp->left != nullptr) {
		tmp = tmp->left;
	}
	return tmp;
}

Leaf* Tree::max()
{
	if (!root) {
		return nullptr;
	}
	//узел для прохода по дереву
	Leaf* tmp = root;

	//спускаемся по левой ветке в самый низ
	while (tmp->right != nullptr) {
		tmp = tmp->right;
	}
	return tmp;
}

void Tree::insert(int value)
{
	//новый узел
	Leaf* newLeaf = new Leaf(value);
	//временный указатель для прохода по дереву
	Leaf* tmp = root;
	//указатель на будущего родителя
	Leaf* futureParent = nullptr;

	//дерево пустое
	if (root == nullptr) {
		root = newLeaf;
	}
	else {
		//поиск места вставки
		while (tmp != nullptr) {
			//запоминаем родителя
			futureParent = tmp;
			//проход влево
			if (value < tmp->value) {
				tmp = tmp->left;
			}
			//проход вправо
			else {
				tmp = tmp->right;
			}
		}

		//запоминаем родителя
		newLeaf->parent = futureParent;
		//прикрепление к родителю
		if (value < futureParent->value) {
			futureParent->left = newLeaf;
		}
		//проход вправо
		else {
			futureParent->right = newLeaf;
		}
	}
}

const Leaf* Tree::getRoot() const
{
	return root;
}

void Tree::clear(Leaf* leaf)
{
	if (leaf) {
		clear(leaf->left);
		clear(leaf->right);
		std::cout << "delete - " << leaf->value << std::endl;
		delete leaf;
	}
}

Leaf* Tree::search(const Leaf* leaf, int value)
{
	//временный узел для прохода
	Leaf* tmp = const_cast<Leaf*>(leaf);
	while (tmp != nullptr) {
		if (value == tmp->value) {
			break;
		}
		else if (value < tmp->value) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	return tmp;
}
