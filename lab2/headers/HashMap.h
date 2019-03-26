#ifndef _HASH_MAP_INCLUDED
#define _HASH_MAP_INCLUDED

#include "LinkedList.h"
#include <string>

using namespace std;

// HashMap класс
class HashMap {
private:
	// Поля
	LinkedList* arr; // Массив связных списков 
	int size; // Размер массива (количество списков)
	int amount; // Общее количество хранимых значений
	const static int defaultSize; // Размер по умолчанию
	const static double maxLoad; // Максимальный допустимый коэффициент заполнения
	// Методы
	void resize(); // Увеличение размера HashMap
	void checkLoad(); // Проверка загрузки HashMap
	int hash(string key); // Хеш функция
public:
	// Конструкторы
	HashMap(); // По умолчанию
	HashMap(int size); // С явной передачей размера
	//Деструктор
	~HashMap();
	// Методы
	void add(string key, string value); // Добавление, хеш на основе переданного ключа
	string find(string key); // Поиск по ключу
};

#endif