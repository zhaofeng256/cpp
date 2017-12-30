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
class Guangdong : public Chinese {
    public:
    virtual void speak() {
        cout << "speak yueyu " << endl;
    }
};


void test_func(Human& h)
{
    h.speak();
    Human *ph;
    English *pe;
    Chinese *pc;
    Guangdong *pg;


    if(ph = dynamic_cast<Human*>(&h))
        cout << "this is human" << endl;
    if(pe = dynamic_cast<English*>(&h))
        cout << "this is english" << endl;
    if(pc = dynamic_cast<Chinese*>(&h))
        cout << "this is chinese" << endl;
    if(pg = dynamic_cast<Guangdong*>(&h))
        cout << "this is guangdongren " << endl;

}
int main(int argc, char **argv)
{
    Human h;
    Chinese c;
    English e;
    Guangdong g;

    test_func(h);
    test_func(c);
    test_func(e);
    test_func(g);

    return 0;
}
