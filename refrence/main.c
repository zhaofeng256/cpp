#include <iostream>
using namespace std;
int add_one(int & a)
{
    a++;
    return a;
}
int main(int argc, char **argv)
{
    int a = 100;
    cout << add_one(a)<<endl;
    return 0;
}
