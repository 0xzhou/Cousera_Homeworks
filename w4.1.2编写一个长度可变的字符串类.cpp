//��дһ�����ȿɱ���ַ�����String
//*����һ��char *���͵ĳ�Ա����points to ��̬����Ĵ洢�ռ�
//*�ô洢�ռ����ڴ��'\0'��β���ַ���
#include<iostream>
#include<string>
using namespace std;

class String {
private:
	char * str;
public:
	String() :str(NULL) {}//���캯������ʼ��strΪNULL
	const char * c_str() { return str; }
	char * operator =(const char * s);// define the overloading operator "="
	~String();
	// ���
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