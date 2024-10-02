#include <iostream>
const float PI = 3.1415926535;
using namespace std;

class Shape {
public:
	virtual float calC() = 0;
};

class Square :public Shape {
private:
	float length;
	float width;
public:
	Square(float l,float w):length(l),width(w){}
	float calC() {
		return 2 * (length + width);
	}
};

class Circle :public Shape {
private:
	float radius;
public:
	Circle(float r) :radius(r) {};
	float calC() {
		return 2 * PI * radius;
	}
};

int main() {
	Square square(2, 3);
	Circle circle(2);
	cout << "正方形周长" << square.calC() << "cm，圆形周长" << circle.calC() << "cm" << endl;
}