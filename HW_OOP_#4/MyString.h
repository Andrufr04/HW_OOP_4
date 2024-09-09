#pragma once
class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(int length);
	MyString(const char* input);
	void input();
	void print();

	void MyStrcpy(MyString& obj);
	~MyString();
};

