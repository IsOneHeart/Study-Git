#include <iostream>  
#include <cmath>  
#include <stdexcept> // �����׼�쳣��  
using namespace std;

// �Զ����쳣��  
class NoRealRootsException : public std::runtime_error {
public:
    NoRealRootsException(const std::string& what_arg)
        : std::runtime_error(what_arg) {}
};

int calculateRoots() {
    using namespace std;

    cout << "����һԪ���η�����Ax^2+Bx+C=0�ĸ���ϵ����" << endl;
    double A, B, C, x1, x2;
    cin >> A >> B >> C;

    if (A == 0) {
        if (B == 0) {
            cout << "�޽�(Warning)! ��ΪA��B��Ϊ0" << endl;
            return 1; // �������˳�����ʾ�������  
        }
        else {
            x1 = -C / B;
            cout << "x1=" << x1 << "����ΪAΪ0��ֻ��һ���⣩" << endl;
            return 0; // �����˳�  
        }
    }

    double discriminant = B * B - 4 * A * C;
    if (discriminant < 0) {
        // �׳��Զ����쳣  
        throw NoRealRootsException("û��ʵ��(Warning)����Ϊ�б�ʽС��0");
    }
    else if (discriminant == 0) {
        x1 = x2 = -B / (2 * A);
        cout << "x1=" << x1 << "��x2=" << x2 << endl;
    }
    else {
        x1 = (-B + sqrt(discriminant)) / (2 * A);
        x2 = (-B - sqrt(discriminant)) / (2 * A);
        cout << "x1=" << x1 << "��x2=" << x2 << endl;
    }

    return 0;
}

int main() {
    try {
        return calculateRoots(); // ����calculateRoots�����������  
    }
    catch (const NoRealRootsException& e) {
        cerr << e.what() << endl; // ���û��ʵ�����쳣��Ϣ  
        return 1; // �������˳�����ʾû��ʵ��  
    }
    catch (const std::exception& e) {
        cerr << "����δ֪�쳣: " << e.what() << endl;
        return 2; // �������˳�����ʾ����δ֪�쳣  
    }
}