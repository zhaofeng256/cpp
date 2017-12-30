#include <iostream>
using namespace std;



class Human{
    public:
    virtual void speak(){
        cout << "speak speach" << endl;
    }
};
class Chinese : public Human {
    public:
    void speak() {
        cout << "speak chinese" << endl;

    }
};


int main(int argc, char **argv)
{
    Chinese c1;
    c1.speak();
    return 0;
}
