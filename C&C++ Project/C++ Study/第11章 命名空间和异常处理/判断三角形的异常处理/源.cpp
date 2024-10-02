#include <iostream>
using namespace std;

int main() {
	cout << "请输入三个数值：";
	double a, b, c;
	cin >> a >> b >> c;
	try {
		if (a + b < c || a + c < b || b + c < a)
			throw exception("不能构成三角形！");
		else {
			cout << "能构成三角形" << endl;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	return 0;
}
