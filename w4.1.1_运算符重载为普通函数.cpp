
class Complex {
public:
	Complex(double r = 0.0, double i = 0.0){//���캯��
	real = r;
    imaginary=i;
	}
	double real;// real part
	double imaginary; // imaginary part
};

Complex operator+(const Complex & a, const Complex & b)
{
	return Complex(a.real + b.real, a.imaginary + b.imaginary);
} //"������������"�ʹ���һ������
int main() {
	Complex a(1, 2), b(2, 3), c;
	c = a + b;//������operator+(a,b)����
}

//����Ϊ��ͨ����ʱ����������Ϊ�����Ŀ������
