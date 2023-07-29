#include<iostream>
#include<string>
using namespace std;
class mystring
{
	char* str;
public:
	mystring()
	{
		str = new char;
		*str = '\0';
	}
	mystring(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	mystring(const mystring& obj)
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
		//str = obj.str;
	}
	mystring& operator=(const mystring& obj)
	{
		if(str!=nullptr)
			delete[] str;
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
		return *this;
	}
	void copy(const char* s)
	{
		if (str != nullptr)
			delete[] str;
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	char* getstring()
	{
		return str;
	}
	void reverse()
	{
		int len = strlen(str);
		int j = 0, i = len - 1;
		for (; j < len / 2; j++, i--)
		{
			char temp = str[j];
			str[j] = str[i];
			str[i] = temp;
		}
	}
	void concate(const char* s) //Concate function
	{
		char* str2 = new char[strlen(str) + strlen(s) + 1];
		strcpy(str2, str);
		int i = strlen(str);
		int j;
		for (j = 0; s[j] != '\0'; j++,i++)
		{
			str2[i] = s[j];
		}
		str2[i] = '\0';
		delete str;
		str = str2;
	}
	int compare(mystring& obj)
	{
		
		return strlen(str) - strlen(obj.str);
	}
	~mystring()
	{
		cout << "\n" << str << "destroying" << endl;
		delete[] str;
	}

};
int main()
{
	mystring obj1;//default constructor invoked
	cout << "obj1:" << obj1.getstring() << endl;
	mystring obj2="Hello";//argument constructor invoked
	cout << "obj2:" << obj2.getstring() << endl;

	mystring obj3 = "Sravani";//argument constructor invoked
	obj3.concate("Podile");
	cout << "obj3:" << obj3.getstring() << endl;
	int i = obj2.compare(obj3);
	if (i > 0)
		cout << obj2.getstring() << " is greater than " << obj3.getstring() << endl;
	else if (i < 0)
		cout << obj3.getstring() << " is greater than " << obj2.getstring() << endl;
	else
		cout << "Both are equal" << endl;
	obj1 = obj2;//obj1.operator=(&obj);overloaded assignment operator
	cout << "obj1:" << obj1.getstring() << endl;
	mystring obj4(obj3);//copy constructor called obj4.mystring(obj3);
	cout << "obj4:" << obj4.getstring() << endl;
	mystring obj5;
	obj5.copy("Welcome");
	cout << "obj5:" << obj5.getstring() << endl;
	int j = obj3.compare(obj4);
	if (j > 0)
		cout << obj3.getstring() << " is greater than " << obj4.getstring() << endl;
	else if (j < 0)
		cout << obj4.getstring() << " is greater than " << obj3.getstring() << endl;
	else
		cout << "Both are equal" << endl;
	mystring obj6 = "Sravani";
	obj6.reverse();
	cout << obj6.getstring() << endl;
	return 0;
}