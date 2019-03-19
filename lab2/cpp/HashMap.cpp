#include "HashMap.h"
#include <string>
#include <iostream>

using namespace std;

// HashMap �����
const int HashMap::defaultSize = 256; // ������ �� ���������
const double HashMap::maxLoad = 80; // ������������ ���������� ����������� ����������

HashMap::HashMap() {
	amount = 0;
	size = defaultSize;
	arr = new LinkedList[size];
}

HashMap::HashMap(int size) {
	this->amount = 0;
	this->size = size;
	this->arr = new LinkedList[this->size];
}

void HashMap::resize() { // ���������� ������� HashMap
	int size_ = size; // ���������� ������ ������
	LinkedList* arr_ = arr; // ���������� ������� ������ �������

	amount = 0;
	size *= 2;
	arr = new LinkedList[size]; // ������� ����� ������ ������� � ��� ���� ������ ��������

	for (int i = 0; i < size_; i++) {
		LinkedList curr = arr_[i];
		for (int j = 0; j < curr.getSize(); i++) {
			ListItem* currItem = curr.get(j);
			arr->add(currItem->getKey(), currItem->getData());
		}
	}
}

void HashMap::checkLoad() { // �������� �������� HashMap
	double loadFactor = amount / size * 100; // ����������� ����������
	if (loadFactor > maxLoad) { // ������� ����������� ���������� ��������� ������������
		resize(); // ����������� ������
	}
}

int HashMap::hash(string str) { // ���������� ����
	int hash = 0;
	for (int i = 0; i < str.length(); i++) {
		hash += abs(static_cast<int>(tolower(str[i])))*(i+1);
	}
	return hash % size;
}

void HashMap::add(string key, string value) { // ����������, ��� �� ������ ����������� �����
	amount++; // �������������� ����� ���������� ���������
	int index = hash(key) % size; // ������� ������� � �������
	arr[index].add(key, value);
	checkLoad(); // ��������� ����������� ���������� HashMap
}

//string HashMap::find(string key) { // ����� �� �����
	//....
<<<<<<< HEAD
//
// loadFactor = 
=======
}
>>>>>>> 32f4bbb27f0a9a119f4b6586230fb30aad21b5eb
