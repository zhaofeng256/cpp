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
};
int main(int argc, char **argv)
{
    Person p = Person();
    Person p2 = Person("jack", 21);
    Person p3();

    Person *p4 = new Person();
    Person *p5 = new Person;
    Person *p6 = new Person[2];
    delete p4;
    delete p5;
    delete []p6;
    Person *p7 = new Person("kate", 20);
    delete p7;
    Person *p8 = new Person("bruce");
    delete p8;
    return 0;
}
