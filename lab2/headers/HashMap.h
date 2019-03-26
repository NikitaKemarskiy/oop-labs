#ifndef _HASH_MAP_INCLUDED
#define _HASH_MAP_INCLUDED

#include "LinkedList.h"
#include <string>

using namespace std;

// HashMap �����
class HashMap {
private:
	// ����
	LinkedList* arr; // ������ ������� ������� 
	int size; // ������ ������� (���������� �������)
	int amount; // ����� ���������� �������� ��������
	const static int defaultSize; // ������ �� ���������
	const static double maxLoad; // ������������ ���������� ����������� ����������
	// ������
	void resize(); // ���������� ������� HashMap
	void checkLoad(); // �������� �������� HashMap
	int hash(string key); // ��� �������
public:
	// ������������
	HashMap(); // �� ���������
	HashMap(int size); // � ����� ��������� �������
	//����������
	~HashMap();
	// ������
	void add(string key, string value); // ����������, ��� �� ������ ����������� �����
	string find(string key); // ����� �� �����
};

#endif