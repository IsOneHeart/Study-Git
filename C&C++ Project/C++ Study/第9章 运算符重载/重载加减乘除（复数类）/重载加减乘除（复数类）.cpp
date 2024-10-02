#include <iostream>
#include <cmath>
#include <limits> // 用于 std::numeric_limits  
using namespace std;

class Complex {
private:
	double real;
	double image;
public:
	Complex() {
		real = 0;
		image = 0;
	}
	Complex(int r,int i):real(r),image(i){}
	operator double() {
		return real;
	}
	operator float() {
		return static_cast<float>(real);
	}
	operator int() {
		return static_cast<int>(real);
	}
	Complex operator+(const Complex& c1) {
		return Complex(real + c1.real, image + c1.image);
	}
	Complex operator-(const Complex& c1) {
		return Complex(real - c1.real, image - c1.image);
	}
	Complex operator*(const Complex& c1) {
		return Complex(real * c1.real - image * c1.image, real * c1.image + image * c1.real);
	}
	Complex operator/(const Complex& c1) {
		double denominator = c1.real * c1.real + c1.image * c1.image;
		if (denominator < std::numeric_limits<double>::epsilon()) { // 检查分母是否接近于0  
			throw std::runtime_error("Division by zero or very small number");
		}
		return Complex((real * c1.real + image * c1.image) / denominator,
			(image * c1.real - real * c1.image) / denominator);
	}
	void show() const {
		if (image > 0) {
			cout << real << "+" << image << "i";
		}
		else if (image < 0) {
			cout << real << "-" << -image << "i";
		}
		else {
			cout << real;
		}
	}
};

int main(){
	Complex z1(1, 2), z2(1, 0);
	cout << "z1=";
	z1.show();
	cout << "\nz2=";
	z2.show();
	cout << "\nz1+z2=";
	(z1 + z2).show();
	cout << "\nz1-z2=";
	(z1 - z2).show();
	cout << "\nz1*z2=";
	(z1 * z2).show();
	cout << "\nz1/z2=";
	try {
		(z1 / z2).show(); // 使用 try-catch 来捕获可能的运行时错误  
	}
	catch (const runtime_error& e) {
		cout << e.what(); // 如果分母太小，打印错误信息  
	}
	return 0;
}
