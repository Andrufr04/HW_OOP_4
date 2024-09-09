#include "MyString.h"
#include<Windows.h>
#include <iostream>
using namespace std;

//	����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
MyString::MyString()  
{
	str = new char[80+1];
	str[0] = '\0';
}
// �����������, ����������� ��������� ������ ������������� �������;
MyString::MyString(int length)
{
	str = new char[length + 1];
	str[0] = '\0';
}
// �����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������. 
MyString::MyString(const char* input)
{
	str = new char[strlen(input) + 1];
	strcpy_s(str, strlen(input) + 1, input);
}

// ������ ��� ����� ����� � ���������� � ������ ����� �� �����.
void MyString::input()
{
	char buff[100];
	cout << "Enter string: ";
	cin.getline(buff, 100);

	if (str != nullptr)
	{
		delete[] str;
	}
	str = new char[strlen(buff) + 1];
	strcpy_s(str, strlen(buff) + 1, buff);
}
void MyString::print()
{
	if (str[0] == '\0')
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << "Your string: " << str << endl;
	}
}

// // ����������� �����
void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[] str;
	}

	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
}

MyString::~MyString()
{
	delete[] str;
}
