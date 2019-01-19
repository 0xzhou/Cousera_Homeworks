//编写一个长度可变的字符串类String
//*包含一个char *类型的成员变量points to 动态分配的存储空间
//*该存储空间用于存放'\0'结尾的字符串
#include<iostream>
#include<string>
using namespace std;

class String {
private:
	char * str;
public:
	String() :str(NULL) {}//构造函数，初始化str为NULL
	const char * c_str() { return str; }
	char * operator =(const char * s);// define the overloading operator "="
	~String();
	// 深拷贝
	String & operator=(const String & s) {
		if (str == s.str)return *this;
		if (str) delete[] str;
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
		return *this;
	}
	//
};

// overload '=', so make obj="hello" possible
// String obj;

char * String::operator=(const char * s) { // s poins to the address of a string.
	if (str) delete[] str;
	if (s) { // if s not NULL, then implements copy
		str = new char[strlen(s) + 1]; // '+1' is to add the '\0'
		strcpy(str, s); // copy "hello" to obj
	}
	else
		str = NULL;
	return str;
}
String::~String() {
	if (str) delete[] str;
}
int main() {
	String s;
	s = "Good Luck,";//s.operator=(" ") ???
	cout << s.c_str() << endl;
	s = "Shenzhou 8!";
	cout << s.c_str() << endl;
		return 0;
}