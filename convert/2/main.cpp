#include <iostream>
using namespace std;


class Human {
    public:
    virtual void speak() {
        cout << "speak speach" << endl;
    }
};
class Chinese : virtual public Human {
    virtual void speak() {
        cout << "speak chinese " << endl;
    }
};
class English : virtual public Human {
    virtual void speak() {
        cout << "speak english " << endl;
    }
};


void test_func(Human& h)
{
    h.speak();
    English *pe;
    Chinese *pc;

    if(pe = dynamic_cast<English*>(&h))
        cout << "this is english" << endl;
    if(pc = dynamic_cast<Chinese*>(&h))
        cout << "this is chinese" << endl;

}
int main(int argc, char **argv)
{
    Human h;
    Chinese c;
    English e;

    test_func(h);
    test_func(c);
    test_func(e);

    return 0;
}
