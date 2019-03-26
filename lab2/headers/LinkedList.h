#ifndef _LINKED_LIST_INCLUDED
#define _LINKED_LIST_INCLUDED

#include <string>

using namespace std;

// ListItem �����
class ListItem {
private:
	string key; // ���� ��������
	string data; // �������� ��������
	ListItem* next; // ������ �� ��������� �������
public:
	// ������������
	ListItem();
	ListItem(string key, string data);
	// �������
	void setNext(ListItem* next); // ���������� ��������� �������
	void setKey(string key); // ���������� ����
	void setData(string data); // ���������� ��������
	// �������
	ListItem* getNext(); // �������� ��������� �������
	string getKey(); // �������� ����
	string getData(); // �������� ��������
};

// LinkedList �����
class LinkedList {
private:
	int Size; // ������ ������
	ListItem* first; // ������ �������
	ListItem* last; // ��������� �������
public:
	// ������������
	LinkedList();
	// ����������
	~LinkedList();
	// ������
	void add(string key, string data); // ���������� �������� � ���� �������� ������
	ListItem* get(int index); // ��������� �������� �� �������
	string find(string key); // ����� �������� �� �����
	int getSize(); // ��������� ������� ������
};

#endif
