//https://zhuanlan.zhihu.com/p/55229582

#include <iostream>
using namespace std;

class Person
{
private:
    int age;
    string name;
    int* data;

public:
    Person() : data(new int[1000000]){}
    ~Person() { delete [] data; }

    // 拷贝构造函数
    Person(const Person& p) :
    age(p.age),
    name(p.name),
    data(new int[1000000]){
        std::copy(p.data, p.data+1000000, data);
        cout << "Copy Constructor" << endl;
    }

    // 拷贝赋值运算符
    Person& operator=(const Person& p){
        this->age = p.age;
        this->name = p.name;
        this->data = new int[1000000];
        std::copy(p.data, p.data+1000000, data);
        cout << "Copy Assign" << endl;
        return *this;
    }

    // 移动构造函数
    Person(Person &&p) :
    age(std::move(p.age)),
    name(std::move(p.name)),
    data(p.data){
        p.data=nullptr; // 源对象的指针应该置空，以免源对象析构时影响本对象
        cout << "Move Constructor" << endl;
    }

    // 移动赋值运算符
    Person& operator=(Person &&p){
        this->age = std::move(p.age);
        this->name = std::move(p.name);
        this->data = p.data;
        p.data=nullptr;
        cout << "Move Assign" << endl;
        return *this;
    }
};

int main(){
    Person p1;
    Person p2 = p1; // 拷贝构造函数

    Person p3,p4;
    p3 = p4; // 拷贝赋值运算符

    Person p5;
    Person p6 = std::move(p5); // 移动构造函数

    Person p7,p8;
    p7 = std::move(p8); // 移动赋值运算符

    return 0;
}

