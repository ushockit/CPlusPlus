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
	//новый узел
	Node* node = new Node;
	node->value = value;

	//список пуст
	if (isEmpty()) {
		head = tail = node;
	}
	else {		//список не пуст
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	count++;
}

void LinkedList::addToHead(int value)
{
	//новый узел
	Node* node = new Node;
	node->value = value;

	//список пуст
	if (isEmpty()) {
		head = tail = node;
	}
	else {		//список не пуст
		node->next = head;
		head->prev = node;
		head = node;
	}
	count++;
}

void LinkedList::removeFromTail()
{
	//список не пуст
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
	//список не пуст
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
	//новый узел
	Node* node = new Node;
	node->value = value;

	//список пуст
	if (isEmpty()) {
		head = tail = node;
	}
	else {	//список не пуст
		Node* tmp = head;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		//правая часть списка
		Node* right = tmp->next;

		//связь нового узла с левой частью списка
		tmp->next = node;
		node->prev = tmp;
		//связь нового узла с правой частью списка
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
	//список не пуст
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
