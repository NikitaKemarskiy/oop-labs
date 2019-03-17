#ifndef _LINKED_LIST_INCLUDED
#define _LINKED_LIST_INCLUDED

#include <string>

using namespace std;

// ListItem класс
class ListItem {
private:
	string key;
	string data;
	ListItem* next;
public:
	// Конструкторы
	ListItem();
	ListItem(string data);
	ListItem(string key, string data);
	ListItem(string data, ListItem* next);
	ListItem(string key, string data, ListItem* next);
	// Сеттеры
	void setNext(ListItem* next);
	void setData(string data);
	// Геттеры
	ListItem* getNext();
	string getKey();
	string getData();
};

// LinkedList класс
class LinkedList {
private:
	int size;
	ListItem* first;
	ListItem* last;
public:
	// Конструкторы
	LinkedList();
	// Методы
	void add(string data);
	void add(string key, string data);
	void remove(string key);
	string find(string key);
	int getSize();
	string toString();
};

#endif