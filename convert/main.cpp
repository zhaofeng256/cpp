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
#if 0
    //English& pe = dynamic_cast<English&>(h);
    Chinese& pc = dynamic_cast<Chinese&>(h);
    Guangdong& pg = dynamic_cast<Guangdong&>(h);
#else
    English& pe = reinterpret_cast<English&>(h);
    Chinese& pc = reinterpret_cast<Chinese&>(h);
    Guangdong& pg = reinterpret_cast<Guangdong&>(h);
#endif

}
int main(int argc, char **argv)
{
    Guangdong g;

    test_func(g);

    return 0;
}
