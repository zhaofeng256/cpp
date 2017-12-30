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
        cout << "Mac computer" << endl;
    }
};

class MacWithLinux : public LinuxOS {
public:
    void InstallOS() {
        cout << "Mac install linux"<< endl;
        Install();
    }
};

class MacWithWindows : public WinOS {
public:
    void InstallOS() {
        cout << "Mac install windows" << endl;
        Install();
    }
};


int main(int argc, char **argv)
{
    MacWithLinux m;
    m.InstallOS();
    return 0;
}
