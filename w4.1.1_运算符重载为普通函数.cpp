
class Complex {
public:
	Complex(double r = 0.0, double i = 0.0){//构造函数
	real = r;
    imaginary=i;
	}
	double real;// real part
	double imaginary; // imaginary part
};

Complex operator+(const Complex & a, const Complex & b)
{
	return Complex(a.real + b.real, a.imaginary + b.imaginary);
} //"类名（参数表）"就代表一个对象
int main() {
	Complex a(1, 2), b(2, 3), c;
	c = a + b;//调用了operator+(a,b)函数
}

//重载为普通函数时，参数个数为运算符目数？？
