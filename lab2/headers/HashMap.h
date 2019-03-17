#ifndef _HASH_MAP_INCLUDED
#define _HASH_MAP_INCLUDED

#include "LinkedList.h"
#include <string>

using namespace std;

// HashMap класс
class HashMap {
private:
	LinkedList* arr; // Массив связных списков 
	int size; // Размер массива (количество списков)
	int amount; // Общее количество хранимых значений
	const static int defaultSize = 256; // Размер по умолчанию
public:
	// Конструкторы
	HashMap(); // По умолчанию
	HashMap(int size); // С явной передачей размера
	// Методы
	void add(string value); // Добавление, хеш на основе самого значения
	void add(string key, string value); // Добавление, хеш на основе переданного ключа
	void remove(string key); // Удаление по ключу
	void resize(); // Увеличение размера HashMap
	string find(string key); // Поиск по ключу
};

#endif
