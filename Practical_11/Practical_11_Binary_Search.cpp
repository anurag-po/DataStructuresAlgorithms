#include <iostream>
using namespace std;

int main()
{
  int n,x,m;
  int r, l=0;

  int a[] = {1,2,5,8,9,25,34,76,81,96};
  n = 10; //Size of Array

  r = n - 1;
  x = 81;

  while (l <= r)
  {
    m = (l + r) / 2; 
    if (a[m] ==x) { cout<<"Element found at index : "<<m; return 0; }
    if (a[m] < x ) l = m + 1;
    else r = m - 1;
  }
  cout << -1;
}
