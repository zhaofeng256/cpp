#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(){}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point& p) {
        cout << "copy constructor" <<endl;
        this->x = p.x;
        this->y = p.y;
    }
    ~Point(){}
    void printInfo() {
        cout << "(" << this->x << "," << this->y << ")" << endl;
    }

    Point operator+(Point& p1){
        Point p;
        p.x = p1.x + this->x;
        p.y = p1.y + this->y;
        return p;
    }

    Point& operator++(void)
    {
        this->x++;
        this->y++;
        return *this;
    }

    Point operator++(int a)
    {
        Point p;
        p = *this;
        this->x++;
        this->y++;
        return p;
    }
        friend ostream& operator<<(ostream &o, Point &p);
};


ostream& operator<<(ostream &o, Point &p)
{
    cout << "(" << p.x << "," << p.y << ")";
    return o;
}

int main(int argc, char **argv)
{
    Point p1(1,2);
    Point p2(3,4);
    Point p3 = p1 + p2;
    cout << "p1+p2"<< endl;
    p3.printInfo();

    cout << "p1++" << endl;
    Point p4 = p1++;
    p4.printInfo();
    p1.printInfo();

    cout << "++p2" << endl;
    Point p5 = ++p2;
    p5.printInfo();
    p2.printInfo();

    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;

    return 0;
}
