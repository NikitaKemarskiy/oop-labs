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
	ListItem(string key, string data);
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
	int Size; // Размер списка
	ListItem* first; // Первый элемент
	ListItem* last; // Последний элемент
public:
	// Конструкторы
	LinkedList();
	// Деструктор
	~LinkedList();
	// Методы
	void add(string key, string data); // Добавление элемента с явно заданным ключом
	ListItem* get(int index); // Получение элемента по индексу
	string find(string key); // Поиск элемента по ключу
	int getSize(); // Получение размера списка
};

#endif
