#include <iostream>
using namespace std;

int main() {
	cout << "������������ֵ��";
	double a, b, c;
	cin >> a >> b >> c;
	try {
		if (a + b < c || a + c < b || b + c < a)
			throw exception("���ܹ��������Σ�");
		else {
			cout << "�ܹ���������" << endl;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	return 0;
}
