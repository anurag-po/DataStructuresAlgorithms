#include <iostream>
using namespace std;

class Queue
{
  int arr[10];
  int front = -1;
  int rear = -1;
  
  void enqueuer(int value)
  {
    if (rear > 9) {cout<<"Queue Full"<<endl; return;}
    arr[++rear] = value;
    if (front == -1) front = 0;
    cout<< "Value Inserted : "<< value;
  }

  void dequeuer()
  {
    if (front == -1) {cout<<"Queue Empty"<<endl; return;}
    front++;
    if (front > rear) {front = -1; rear = -1;}
  }

  void display()
  {
    for (int i = front; i <= rear; i++)
    {
      cout<<arr[i]<<" <-- ";
    }
  }
};

int main()
{
  Queue queue;
  queue.enqueuer(10);
  queue.enqueuer(20);
  queue.display();
  queue.dequeuer();
  queue.display();
}
