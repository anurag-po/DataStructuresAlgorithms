#include <iostream>
using namespace std;

void value(int a) { a = 100; }
void reference(int &a) { a = 100; }

int main()
{
    int x = 10;

    value(x);
    cout << "After Call by Value: " << x << endl;

    reference(x);
    cout << "After Call by Reference: " << x << endl;

    return 0;
}
