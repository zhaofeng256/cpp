#include <iostream>
#include <string.h>
#include <utils/RefBase.h>

using namespace std;
using namespace android;

class Person : public RefBase {
    private:
    wp<Person> father;
    wp<Person> son;
    string name;
    public:
    Person(){
        cout << "Person constructor" << endl;
    }
    Person(string name) : name(name){
        cout << "Person constructor:" << this->name  << endl;
    }
    ~Person() {
        cout << "Person distructor" << endl;
    }
    void setFather(sp<Person>& father) {
        this->father = father;
    }
    void setSon(sp<Person>& son) {
        this->son = son;
    }

    string getName() {
        return this->name;
    }
    void printInfo() {
        sp<Person> f = father.promote();
        sp<Person> s = son.promote();
        if(f != 0)
            cout << "fatehr name : " << f->getName() << endl;
        if(s != 0)
        cout << "son name: " << s->getName() << endl;
    }
};


int main(int argc, char **argv)
{
    sp<Person> father = new Person("daddy");
    sp<Person> son  = new Person("sonny");
    father->setSon(son);
    father->printInfo();
    son->setFather(father);
    son->printInfo();


    return 0;
}
