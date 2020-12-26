#include "LinkedList.h"

LinkedList::LinkedList()
{
	count = 0;
	head = tail = nullptr;
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::addToTail(int value)
{
	//����� ����
	Node* node = new Node;
	node->value = value;

	//������ ����
	if (isEmpty()) {
		head = tail = node;
	}
	else {		//������ �� ����
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	count++;
}

void LinkedList::addToHead(int value)
{
	//����� ����
	Node* node = new Node;
	node->value = value;

	//������ ����
	if (isEmpty()) {
		head = tail = node;
	}
	else {		//������ �� ����
		node->next = head;
		head->prev = node;
		head = node;
	}
	count++;
}

void LinkedList::removeFromTail()
{
	//������ �� ����
	if (!isEmpty()) {
		Node* tmp = tail->prev;
		delete tail;
		tail = tmp;

		if (tail != nullptr) {
			tail->next = nullptr;
		}

		count--;
	}
}

void LinkedList::removeFromHead()
{
	//������ �� ����
	if (!isEmpty()) {
		Node* tmp = head->next;
		delete head;
		head = tmp;

		if (head != nullptr) {
			head->prev = nullptr;
		}
		count--;
	}
}

void LinkedList::insert(int value, int index)
{
	//����� ����
	Node* node = new Node;
	node->value = value;

	//������ ����
	if (isEmpty()) {
		head = tail = node;
	}
	else {	//������ �� ����
		Node* tmp = head;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		//������ ����� ������
		Node* right = tmp->next;

		//����� ������ ���� � ����� ������ ������
		tmp->next = node;
		node->prev = tmp;
		//����� ������ ���� � ������ ������ ������
		node->next = right;
		right->prev = node;
	}
	count++;
}

void LinkedList::removeAt(int index)
{
}

bool LinkedList::isEmpty()
{
	return head == nullptr;
}

void LinkedList::print()
{
	//������ �� ����
	if (!isEmpty()) {
		Node* tmp = head;

		while (tmp != nullptr) {
			std::cout << tmp->value << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
}

void LinkedList::clear()
{
	if (!isEmpty()) {
		while (!isEmpty()) {
			removeFromHead();
		}
		head = tail = nullptr;
	}
}
