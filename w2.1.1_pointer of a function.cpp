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
	pf = PrintMin;//������һ��ԭ��ƥ��ĺ��������ָ�һ������ָ�븳ֵ
	pf(x, y);//ͨ��ָ���������ָ��ĺ���
	return 0;
}