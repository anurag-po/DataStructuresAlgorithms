#include <iostream>
using namespace std;

int main()
{
  int a[] = {5,3,8,4,2}, n = 5;

  for (int i =0; i < n-1; i++)
  {
    for (int j = 0; j < n-1-i; j++)
    {
      if (a[j] > a[j+1]) { int temp = a[j+1]; a[j+1] = a[j]; a[j] = temp; }
    }
  }

  for (int i = 0; i < n; i++) cout<<a[i]<<" ";
  return 0;
}

