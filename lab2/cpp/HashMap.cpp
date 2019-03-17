#include "HashMap.h"
#include <string>

using namespace std;

// HashMap класс
const int HashMap::defaultSize = 256; // Размер по умолчанию
const double HashMap::maxLoad = 80; // Максимальный допустимый коэффициент заполнения

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

void HashMap::add(string value) { // Добавление, хеш на основе самого значения
	amount++;
	//...
	checkLoad();
}

void HashMap::add(string key, string value) { // Добавление, хеш на основе переданного ключа
	amount++;
	//...
	checkLoad();
}

void HashMap::remove(string key) { // Удаление по ключу
	//...
}

void HashMap::resize() { // Увеличение размера HashMap
	int size_ = size; // Запоминаем старый размер
	LinkedList* arr_ = arr; // Запоминаем текущий массив списков
	
	amount = 0;
	size *= 2;
	arr = new LinkedList[size]; // Создаем новый массив списков в два раза больше размером
	
	for (int i = 0; i < size_; i++) {
		LinkedList curr = arr_[i];
		for (int j = 0; j < curr.getSize(); i++) {
			ListItem* currItem = curr.get(j);
			arr->add(currItem->getKey(), currItem->getData());
		}
	}
}

void HashMap::checkLoad() { // Проверка загрузки HashMap
	double loadFactor = amount / size * 100; // Коэффициент заполнения
	if (loadFactor > maxLoad) { // Текущий коэффициент заполнения превышает максимальный
		resize(); // Увеличиваем размер
	}
}

string HashMap::find(string key) { // Поиск по ключу
	//....
}


// loadFactor = 