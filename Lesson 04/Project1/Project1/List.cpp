#include "List.h"

List::List()
{
	head = tail = nullptr;
	count = 0;
}

List::~List()
{
	clear();
}

void List::addToTail(int value)
{
	//����� ����
	Node* node = new Node;
	node->value = value;

	//������ ���� (���������� ������� ��������)
	if (isEmpty()) {
		head = tail = node;
	}
	else {	//������ �� ����
		tail->next = node;
		tail = node;
	}
	count++;
}

void List::addToHead(int value)
{
	//����� ����
	Node* node = new Node;
	node->value = value;

	//������ ���� (���������� ������� ��������)
	if (isEmpty()) {
		head = tail = node;
	}
	else {
		node->next = head;
		head = node;
	}
	count++;
}

void List::removeFromTail()
{
	//������ �� ����
	if (!isEmpty()) {
		//��������� ��������� ��� ������� �� ������
		Node* tmp = head;

		//������� ������
		while (tmp->next != nullptr && tmp->next != tail) {
			tmp = tmp->next;
		}


		if (count == 1) {
			delete tmp;
			head = tail = nullptr;
		}
		else {
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}

		count--;
	}
}

void List::removeFromHead()
{
	//������ �� ����
	if (!isEmpty()) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
		count--;
	}
}

void List::removeAt(int index)
{
	//������ �� ���� & ������ �� ������� �� ������ ������
	if (!isEmpty() && index < count - 1) {
		//��������� ���������� ��� ������� �� ������
		Node* tmp = head;

		for (int idx = 0; idx < index - 1; idx++)
		{
			tmp = tmp->next;
		}
		//������ ����� ������
		Node* right = tmp->next->next;
		delete tmp->next;
		tmp->next = right;
	}
}

bool List::isEmpty()
{
	return head == nullptr;
}

void List::print()
{
	//��������� ���������� ��� ������� �� ������
	Node* tmp = head;

	if (!isEmpty()) {
		while (tmp != nullptr) {
			std::cout << tmp->value << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
}

void List::clear()
{
	if (!isEmpty()) {
		//��������� ��������� ��� ������� �� ������
		/*Node* tmp = head;

		while (tmp != nullptr) {
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
		head = tail = nullptr;*/

		while (!isEmpty()) {
			removeFromHead();
		}
		head = tail = nullptr;
	}
}
