#include <stdio.h>
#include <stdlib.h>
int Mycompare(const void * elem1, const void * elem2)//定义qsort函数的参数函数
{
	unsigned int *p1, *p2;
	p1 = (unsigned int *)elem1;
	p2 = (unsigned int *)elem2;
	return (*p1 % 10) - (*p2 % 10);//按个位数从小到大排序
}
#define NUM 5
int main()
{
	unsigned int an[NUM] = { 8,123,11,10,4 };
	qsort(an, NUM, sizeof(unsigned int), Mycompare);
	for (int i = 0; i < NUM; i++)
		printf("%d ", an[i]);
		return 0;
}