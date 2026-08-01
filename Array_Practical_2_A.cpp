#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\nArray in reverse order:\n";

    int *ptr = arr + size - 1;

    while (ptr >= arr)
    {
        cout << *ptr << " ";
        ptr--;
    }

    delete[] arr;

    return 0;
}
