#include <stdio.h>
void PrintMin(int a, int b) {//declare a function,which print the smaller int among two
	if (a < b)
		printf("%d", a);
	else
		printf("%d", b);
}
int main() {
	void(*pf)(int, int);//declare a pointer to a function
	int x = 4, y = 5;
	pf = PrintMin;//可以用一个原型匹配的函数的名字给一个函数指针赋值
	pf(x, y);//通过指针调用它所指向的函数
	return 0;
}