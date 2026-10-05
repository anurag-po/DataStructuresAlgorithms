#include <iostream>

int main()
{
  int a[] = {5,3,8,2,4};
  for (int i = 0; i < n - 1; i++)
  {
    int m = i;
    for (int j = i + 1; j < n; j++)
    {if (a[j] < a[m]) m = j;}
    int temp = a[i];
    a[i] = a[m];
    a[m] = temp;
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}

