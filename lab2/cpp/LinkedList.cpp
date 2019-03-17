#include "LinkedList.h"
#include <string>

using namespace std;

// ListItem класс
ListItem::ListItem() {
	key = "";
	data = "";
	next = nullptr;
}

ListItem::ListItem(string data) {
	this->key = data;
	this->data = data;
	next = nullptr;
}

ListItem::ListItem(string key, string data) {
	this->key = key;
	this->data = data;
	next = nullptr;
}

ListItem::ListItem(string data, ListItem* next) {
	this->key = data;
	this->data = data;
	this->next = next;
}

ListItem::ListItem(string key, string data, ListItem* next) {
	this->key = key;
	this->data = data;
	this->next = next;
}

void ListItem::setNext(ListItem* next) {
	this->next = next;
}

void ListItem::setData(string data) {
	this->data = data;
}

ListItem* ListItem::getNext() {
	return next;
}

string ListItem::getKey() {
	return key;
}

string ListItem::getData() {
	return data;
}

// LinkedList класс
LinkedList::LinkedList() {
	size = 0;
	first = nullptr;
	last = nullptr;
}

void LinkedList::add(string data) {
	size++; // Инкрементируем размер
	ListItem* last_ = last;
	last = new ListItem(data);
	if (!last_) { // Список был пуст
		first = last;
	} else { // В списке были элементы
		last_->setNext(last); // Ставим указатель на последний элемент
	}
}

void LinkedList::add(string key, string data) {
	size++; // Инкрементируем размер
	ListItem* last_ = last;
	last = new ListItem(key, data);
	if (!last_) { // Список был пуст
		first = last;
	} else { // В списке были элементы
		last_->setNext(last); // Ставим указатель на последний элемент
	}
}

void LinkedList::remove(string key) {
	ListItem* curr = first;
	ListItem* prev = nullptr;
	while (curr) { // Пока не дойдем до последнего элемента
		if (curr->getKey() == key) { // Элемент для удаления найден
			if (prev) { // Есть предыдущий элемент
				size--;
				prev->setNext(curr->getNext());
				delete curr;
				break;
			} else { // Нет предыдущего элемента
				size--;
				first = curr->getNext();
				delete curr;
				break;
			}
		}
		prev = curr; // Присваиваем текущий элемент предыдущему
		curr = curr->getNext(); // Присваиваем следующий элемент текущему
	}
}

string LinkedList::find(string key) {
	ListItem* curr = first;
	while (curr) { // Пока не дойдем до последнего элемента
		if (curr->getKey() == key) { // Элемент найден
			return curr->getData();
		}
		curr = curr->getNext();
	}
}

int LinkedList::getSize() {
	return size;
}

string LinkedList::toString() {
	string str = "[";
	ListItem* curr = first;
	while (curr) { // Пока не дойдем до последнего элемента
		str += "(" + curr->getKey() + "; " + curr->getData() + ")";
		curr = curr->getNext();
	}
	str += "]";
	return str;
}