#include <iostream>
using namespace std;
class Parent
{
    public:
    int a = 5;
    virtual int f() = 0;
};

class Child: public Parent
{
    public:
    int b = 10;
    int f() { return 0; }
};

int main()
{
    Parent* asd = new Child();
    cout << ((Child*)(asd))->b << endl;
    return 0;
}