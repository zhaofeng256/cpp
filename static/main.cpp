#include <iostream>
using namespace std;

class Person{
public:
    static int cnt;
    static int getCount();
    Person() {cnt++;}
};

int Person::cnt = 0;
int Person::getCount()
{
    return cnt;
}

int main(int argc, char **argv)
{
    Person p;
    Person p2;
    Person pn[100];

    cout << "cnt " <<  Person::getCount() << endl;
    cout << "cnt " <<  p.cnt << endl;
    cout << "cnt " <<  pn[0].cnt << endl;
    cout << "cnt " <<  pn[8].cnt << endl;
    return 0;

}
