#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
class Singleton;
Singleton *gInstance;
class Singleton {
    public:
    static Singleton * getInstance() {
        if(NULL == gInstance)
            gInstance = new Singleton();
        return gInstance;
    }
    Singleton() {
        cout << "constructor" << endl;
    }

    void printInfo() {
        cout << "info" << endl;
    }
};

int main(int argc, char **argv)
{
    Singleton *s = Singleton::getInstance();
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    s->printInfo();
    return 0;

}
