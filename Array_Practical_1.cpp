#include <iostream>
using namespace std;

class Array
{
private:
    int *arr;
    int size;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    ~Array()
    {
        delete[] arr;
    }

    void insert(int value)
    {
        int *temp = new int[size + 1];

        for (int i = 0; i < size; temp[i] = arr[i], i++);

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;

        cout << "Done.\n";
    }

    void remove(int value)
    {
        if (size == 0)
        {
            cout << "Array Empty.\n";
            return;
        }

        int index = -1;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Element not found.\n";
            return;
        }

        int *temp = (size == 1) ? nullptr : new int[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i == index)
                continue;

            temp[j++] = arr[i];
        }

        delete[] arr;
        arr = temp;
        size--;

        cout << "Done.\n";
    }

    void traverse()
    {
        if (size == 0)
        {
            cout << "Array Empty.\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void search(int value)
    {
        if (size == 0)
        {
            cout << "Array Empty.\n";
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                cout << "Element found at index " << i << ".\n";
                return;
            }
        }

        cout << "Element not found.\n";
    }
};

int main()
{
    Array a;

    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.insert(40);

    a.traverse();

    a.search(30);
    a.search(100);

    a.remove(20);
    a.traverse();

    a.remove(100);

    return 0;
}
