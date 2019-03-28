
class Complex {
public:
	Complex(double r = 0.0, double m = 0.0):
		real(r), imaginary(m) {}// constructor
	Complex operator+ (const Complex &);
	Complex operator-(const Complex &);
private:
	double real;
	double imaginary;
};
// Overloaded addition operator
Complex Complex::operator+(const Complex & operand2) {
	return Complex(real + operand2.real, imaginary + operand2.imaginary);
}
// Overloaded subtraction operator
Complex Complex::operator-(const Complex & operand2) {
	return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

int main() {
	Complex x, y(4.3, 8.2), z(3.3, 1.1);
	x = y + z;// x=y.operator+(z);
	x = y - z;// x=y.operator-(z)
	return 0;
}

//重载为成员函数时，参数个数为运算符目数减一