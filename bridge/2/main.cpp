#include <iostream>
using namespace std;

class OS {
public:
    virtual void Install() = 0;
};

class LinuxOS : public OS {
public:
    void Install() {cout << "LinuxOS" << endl;}

};

class WinOS : public OS {
public:
    void Install() {cout << "WinOS" << endl;}

};

class Computer{
public:
    virtual void printInfo() = 0;

};
class Mac: public Computer {
public:
    virtual void printInfo(){
        cout << "Mac computer with "<<  endl;
        s->Install();
    }
    Mac(OS* s) {
        this->s = s;
    }
private:
    OS *s;
    Mac(){};
};



int main(int argc, char **argv)
{
    OS *s1 = new LinuxOS();
    OS *s2 = new WinOS();
    Mac m1(s1);
    Mac m2(s2);
    m1.printInfo();
    m2.printInfo();
    delete s1;
    delete s2;
    return 0;
}
