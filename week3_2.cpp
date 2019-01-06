#include<iostream>;
using namespace std;
class Sample {
public:
	int v;
	Sample(int n):v(n)//构造函数初始化列表
	{}
	
	Sample(Sample& a) {//返回值为Sample构造函数
		v = 2 * a.v;
	}
};
int main() {
	Sample a(5);
	Sample b = a;
	cout << b.v;
	return 0;
}
