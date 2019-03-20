#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

// ListItem класс
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

void ListItem::setNext(ListItem* next) { // Установить следующий элемент
	this->next = next;
}

void ListItem::setKey(string key) { // Установить ключ
	this->key = key;
}

void ListItem::setData(string data) { // Установить значение
	this->data = data;
}

ListItem* ListItem::getNext() { // Получить следующий элемент
	return next;
}

string ListItem::getKey() { // Получить ключ
	return key;
}

string ListItem::getData() { // Получить значение
	return data;
}

// LinkedList класс
LinkedList::LinkedList() {
	size = 0;
	first = nullptr;
	last = nullptr;
}

void LinkedList::add(string key, string data) { // Добавление элемента с явно заданным ключом
	size++; // Инкрементируем размер
	ListItem* last_ = last;
	last = new ListItem(key, data);
	if (!last_) { // Список был пуст
		first = last;
	}
	else { // В списке были элементы
		last_->setNext(last); // Ставим указатель на последний элемент
	}
}

ListItem* LinkedList::get(int index) { // Получение элемента по индексу
	if (index < 0 || index >= size) { // Неверный индекс
		cout << "invalid index was passed." << endl; // Выводим информацию об ошибке
		cin.get();
		exit(1);
	}
	ListItem* curr = first;
	int currIndex = 0;
	while (curr) { // Пока не дойдем до последнего элемента
		if (currIndex == index) { // Элемент найден
			return curr;
		}
		currIndex++;
		curr = curr->getNext();
	}
	cout << "invalid index was passed." << endl; // Выводим информацию об неверном индексе
	cin.get();
	exit(1);
}

string LinkedList::find(string key) { // Поиск элемента по ключу
	ListItem* curr = first;
	while (curr) { // Пока не дойдем до последнего элемента
		if (curr->getKey() == key) { // Элемент найден
			return curr->getData();
		}
		curr = curr->getNext();
	}
	return "Error with searching item.";
}

int LinkedList::getSize() { // Получение размера списка
	return size;
}