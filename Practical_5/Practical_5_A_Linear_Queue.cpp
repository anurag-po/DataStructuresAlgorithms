#include <iostream>
using namespace std;

class Queue
{
private:
  int arr[10];
  int front = -1;
  int rear = -1;
  
public: 
  void enqueuer(int value)
  {
    if (rear == 9) {
      cout << "Queue Full" << endl; 
      return;
    }
    arr[++rear] = value;
    if (front == -1) front = 0;
    cout << "Value Inserted : " << value << endl;
  }

  void dequeuer()
  {
    if (front == -1) {
      cout << "Queue Empty" << endl; 
      return;
    }
    cout << "Value Dequeued : " << arr[front] << endl;
    front++;
    if (front > rear) {
      front = -1; 
      rear = -1;
    }
  }

  void display()
  {
    if (front == -1) {
      cout << "Queue is Empty" << endl;
      return;
    }
    for (int i = front; i <= rear; i++)
    {
      cout << arr[i] << " <-- ";
    }
    cout << "END" << endl; 
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
  
  return 0;
}
