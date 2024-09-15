#pragma once
class MyString
{
	char* str;
	int length;
	static int countLiveObj;
public:
	MyString();
	MyString(int length);
	MyString(const char* input);
	void input();
	void print();

	int MyStrLen();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* _str);
	int MyChr(char c);
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);


	const char* getStr();

	static int GetCount();
	~MyString();
};

