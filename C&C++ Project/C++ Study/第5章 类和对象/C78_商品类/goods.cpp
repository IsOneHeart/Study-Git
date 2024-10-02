#include <iostream>
#include <string>
using namespace std;

class Goods {
private:
    string name;
    float price;
    string releaseDate;
    string expiryDate;
public:
    void setGoods(string n, float p, string rd, string ed) {
        name = n;
        price = p;
        releaseDate = rd;
        expiryDate = ed;
    }
    void showGoods();
};

void Goods::showGoods() {
    cout << "商品名称：" << name << endl;
    cout << "价格：" << price << endl;
    cout << "出厂日期：" << releaseDate << endl;
    cout << "保质期：" << expiryDate << endl;
}

int main(){
    class Goods g1;
    g1.setGoods("绿箭脆皮薄荷糖 柠檬薄荷味", 13.5, "2023年10月20日生产", "15个月");
    g1.showGoods();
    return 0;
}
