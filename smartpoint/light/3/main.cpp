#include <iostream>
#include <utils/RefBase.h>

using namespace std;
using namespace android;

class Person : public RefBase {
    private:
    wp<Person> father;
    wp<Person> son;
    public:
    Person(){
        cout << "Person constructor" << endl;
    }
    ~Person() {
        cout << "Person distructor" << endl;
    }
    void setFather(wp<Person>& father) {
        this->father = father;
    }
    void setSon(wp<Person>& son) {
        this->son = son;
    }
};


int main(int argc, char **argv)
{
    wp<Person> father = new Person();
    wp<Person> son  = new Person();


    return 0;
}
