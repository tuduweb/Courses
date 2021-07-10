#include <iostream>
using namespace std;

class Circle{
private:
    double x, y, r;
public:
    Circle(double x1, double y1, double r1){ x = x1; y = y1; r = r1; }
    operator int() { return int(r); }
    operator double() { return 2*3.14*r; }
    operator float() { return (float)3.14*r*r; }
};

int main()
{
    Circle c(2.3, 2.4, 2.5);
    int r = c;
    double length = c;
    float area = c;
    double len = (double)c;
    
    cout << r << endl;
    cout << length << endl;
    cout << len << endl;
    cout << area << endl;
    system("pause");
    return 0;
}