#include "MyString.h"
#include<Windows.h>
#include <iostream>
using namespace std;

int MyString::countLiveObj = 0;

MyString::MyString()  
{
	str = new char[80+1];
	str[0] = '\0';
	countLiveObj++;
}
MyString::MyString(int length)
{
	str = new char[length + 1];
	str[0] = '\0';
	countLiveObj++;
}
MyString::MyString(const char* input)
{
	str = new char[strlen(input) + 1];
	strcpy_s(str, strlen(input) + 1, input);
	countLiveObj++;
}


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

int MyString::MyStrLen()
{
	return strlen(str);
}
void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;

	str = new char[obj.MyStrLen() + 1];
	strcpy_s(str, obj.MyStrLen() + 1, obj.getStr());
}
bool MyString::MyStrStr(const char* _str)
{
	char* result = strstr(str, _str);

	if (result != nullptr) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
int MyString::MyChr(char c)
{
	char* pos = strchr(str, c);
	if (pos != nullptr)
	{
		return pos - str;
	}
	return -1;
}
void MyString::MyStrCat(MyString& b)
{
	int newLength = MyStrLen() + b.MyStrLen() + 1;
	char* temp = new char[newLength];

	strcpy_s(temp, MyStrLen() + 1, str);
	strcat_s(temp, newLength, b.str);

	delete[] str;
	str = temp;
}
void MyString::MyDelChr(char c)
{
	int len = MyStrLen();
	char* temp = new char[len + 1];
	int j = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] != c)
		{
			temp[j++] = str[i];
		}
	}

	temp[j] = '\0';

	delete[] str;
	str = temp;
}
int MyString::MyStrCmp(MyString& b)
{
	int result = strcmp(str, b.str);

	if (result < 0) 
	{
		return -1;
	}
	else if (result > 0) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

const char* MyString::getStr()
{
	return str;
}

int MyString::GetCount()
{
	return countLiveObj;
}

MyString::~MyString()
{
	delete[] str;
	countLiveObj--;
}
