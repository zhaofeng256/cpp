#include <iostream>
using namespace std;
class Person {
private:
    string name;
    int age;
    string work;
public:
    Person() {cout << "Person()" <<endl;}
    Person(string name,int age = 10) {
        this->name = name;
        this->age = age;
        cout << "name: " << this->name << " age: " << this->age << endl;
    }

    Person(Person &p) {
        cout << "copy constructor" << endl;
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
    ~Person() { cout << "distruct name : " << name << endl; }
};
void test_fun()
{
    Person p1("jimmy", 12);
    Person p2(p1);
}
int main(int argc, char **argv)
{
    test_fun();
    return 0;
}
