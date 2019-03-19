#include "LinkedList.h"
#include <string>
#include <stdexcept>

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
		throw out_of_range("invalid index was passed."); // Кидаем исключение
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
	throw out_of_range("invalid index was passed."); // Неверный индекс, кидаем исключение
}

/*string LinkedList::find(string key) { // Поиск элемента по ключу
	ListItem* curr = first;
	while (curr) { // Пока не дойдем до последнего элемента
		if (curr->getKey() == key) { // Элемент найден
			return curr->getData();
		}
		curr = curr->getNext();
	}
}*/

int LinkedList::getSize() { // Получение размера списка
	return size;
}

string LinkedList::toString() { // Конвертация в строку
	string str = "[";
	ListItem* curr = first;
	while (curr) { // Пока не дойдем до последнего элемента
		str += "(" + curr->getKey() + "; " + curr->getData() + ")";
		curr = curr->getNext();
	}
	str += "]";
	return str;
}