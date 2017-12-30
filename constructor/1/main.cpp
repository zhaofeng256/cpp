#include <iostream>
using namespace std;
class Person {
private:
    string name;
    int age;
    string work;

public:
    Person() {cout << "Person()" <<endl;}
    Person(string name,int age) {
        this->name = name;
        this->age = age;
        cout << "name: " << this->name << " age: " << this->age << endl;
    }

};



int main(int argc, char **argv)
{
    Person p = Person();
    Person p2 = Person("jack", 21);
    return 0;

}
