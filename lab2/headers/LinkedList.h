#ifndef _LINKED_LIST_INCLUDED
#define _LINKED_LIST_INCLUDED

#include <string>

using namespace std;

// ListItem класс
class ListItem {
private:
	string key; // Ключ элемента
	string data; // Значение элемента
	ListItem* next; // Ссылка на следующий элемент
public:
	// Конструкторы
	ListItem();
	ListItem(string data);
	ListItem(string key, string data);
	ListItem(string data, ListItem* next);
	ListItem(string key, string data, ListItem* next);
	// Сеттеры
	void setNext(ListItem* next); // Установить следующий элемент
	void setKey(string key); // Установить ключ
	void setData(string data); // Установить значение
	// Геттеры
	ListItem* getNext(); // Получить следующий элемент
	string getKey(); // Получить ключ
	string getData(); // Получить значение
};

// LinkedList класс
class LinkedList {
private:
	int size; // Размер списка
	ListItem* first; // Первый элемент
	ListItem* last; // Последний элемент
public:
	// Конструкторы
	LinkedList();
	// Методы
	void add(string data); // Добавление элемента
	void add(string key, string data); // Добавление элемента с явно заданным ключом
	void remove(string key); // Удаление элемента по ключу
	ListItem* get(int index); // Получение элемента по индексу
	string find(string key); // Поиск элемента по ключу
	int getSize(); // Получение размера списка
	string toString(); // Конвертация в строку
};

#endif