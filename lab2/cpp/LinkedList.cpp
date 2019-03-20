#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

// ListItem �����
ListItem::ListItem() {
	key = "";
	data = "";
	next = nullptr;
}

ListItem::ListItem(string key, string data) {
	this->key = key;
	this->data = data;
	next = nullptr;
}

void ListItem::setNext(ListItem* next) { // ���������� ��������� �������
	this->next = next;
}

void ListItem::setKey(string key) { // ���������� ����
	this->key = key;
}

void ListItem::setData(string data) { // ���������� ��������
	this->data = data;
}

ListItem* ListItem::getNext() { // �������� ��������� �������
	return next;
}

string ListItem::getKey() { // �������� ����
	return key;
}

string ListItem::getData() { // �������� ��������
	return data;
}

// LinkedList �����
LinkedList::LinkedList() {
	size = 0;
	first = nullptr;
	last = nullptr;
}

void LinkedList::add(string key, string data) { // ���������� �������� � ���� �������� ������
	size++; // �������������� ������
	ListItem* last_ = last;
	last = new ListItem(key, data);
	if (!last_) { // ������ ��� ����
		first = last;
	}
	else { // � ������ ���� ��������
		last_->setNext(last); // ������ ��������� �� ��������� �������
	}
}

ListItem* LinkedList::get(int index) { // ��������� �������� �� �������
	if (index < 0 || index >= size) { // �������� ������
		cout << "invalid index was passed." << endl; // ������� ���������� �� ������
		cin.get();
		exit(1);
	}
	ListItem* curr = first;
	int currIndex = 0;
	while (curr) { // ���� �� ������ �� ���������� ��������
		if (currIndex == index) { // ������� ������
			return curr;
		}
		currIndex++;
		curr = curr->getNext();
	}
	cout << "invalid index was passed." << endl; // ������� ���������� �� �������� �������
	cin.get();
	exit(1);
}

string LinkedList::find(string key) { // ����� �������� �� �����
	ListItem* curr = first;
	while (curr) { // ���� �� ������ �� ���������� ��������
		if (curr->getKey() == key) { // ������� ������
			return curr->getData();
		}
		curr = curr->getNext();
	}
	return "Error with searching item.";
}

int LinkedList::getSize() { // ��������� ������� ������
	return size;
}