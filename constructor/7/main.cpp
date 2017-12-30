#include <iostream>
using namespace std;
class Person {
public:
    string name;
    int age;
    string work;
    Person() {cout << "Person()" <<endl;}
    Person(string name,int age = 10) {
        this->name = name;
        this->age = age;
        cout << "name: " << this->name << " age: " << this->age << endl;
    }

    Person(Person &p) {
        cout << "copy constructor" << endl;
        this->name = p.name;
        this->age = p.age;
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
    ~Person() { cout << "distruct name : " << name << endl; }
};
Person p("public", 100);
class Student {
public:
    Person father;
    Person mother;
    Student() {
        cout << "student constructor" << endl;
    }
    Student(Person &father, Person &mother):mother(mother),father(father){
        cout << "student constructor mother name:" << mother.name << ", father name: " << father.name << endl;
    }
    ~Student() {
        cout << "student distructor" << endl;
    }
};
void test_fun()
{
    Person p1("father", 32);
    Person p2("mother", 30);
    Student s(p1, p2);
}
int main(int argc, char **argv)
{
    test_fun();
    return 0;
}
