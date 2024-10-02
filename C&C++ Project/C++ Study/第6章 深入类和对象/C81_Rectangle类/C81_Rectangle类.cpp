#include <iostream>
using namespace std;

class Rectangle {
private:
    float width;
    float length;
public:
    Rectangle() {
        width = 2;
        length = 2;
    }
    void setRectangle(float w,float l) {
        width = w;
        length = l;
    }
    float C() {
        return 2 * width + 2 * length;
    }
    float S() {
        return width * length;
    }
};

int main(){
    Rectangle r;
    cout << "C=" << r.C() << endl;
    cout << "S=" << r.S() << endl;
    r.setRectangle(3, 4);
    cout << "C=" << r.C() << endl;
    cout << "S=" << r.S() << endl;
    return 0;
}
