#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	//������� ������ ������������ �����
	clear(root);
	system("pause");
}

void Tree::print(const Leaf* leaf)
{
	//���� ����������
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
	//���� ��� ������� �� ������
	Leaf* tmp = root;

	//���������� �� ����� ����� � ����� ���
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
	//���� ��� ������� �� ������
	Leaf* tmp = root;

	//���������� �� ����� ����� � ����� ���
	while (tmp->right != nullptr) {
		tmp = tmp->right;
	}
	return tmp;
}

void Tree::insert(int value)
{
	//����� ����
	Leaf* newLeaf = new Leaf(value);
	//��������� ��������� ��� ������� �� ������
	Leaf* tmp = root;
	//��������� �� �������� ��������
	Leaf* futureParent = nullptr;

	//������ ������
	if (root == nullptr) {
		root = newLeaf;
	}
	else {
		//����� ����� �������
		while (tmp != nullptr) {
			//���������� ��������
			futureParent = tmp;
			//������ �����
			if (value < tmp->value) {
				tmp = tmp->left;
			}
			//������ ������
			else {
				tmp = tmp->right;
			}
		}

		//���������� ��������
		newLeaf->parent = futureParent;
		//������������ � ��������
		if (value < futureParent->value) {
			futureParent->left = newLeaf;
		}
		//������ ������
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
	//��������� ���� ��� �������
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
