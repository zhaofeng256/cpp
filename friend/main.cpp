#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(){}
    Point(int x, int y):x(x), y(y) {}
    void printInfo() { 
        cout << "x:" << x << " y: " << y;
    }
friend Point add(Point &p1, Point &p2);
};

Point add(Point &p1, Point &p2)
{
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}
int main(int argc, char **argv)
{
    Point p(1, 2);
    Point p2(3, 4);
    Point p3 = add(p, p2);
    p3.printInfo();
    return 0;
}
