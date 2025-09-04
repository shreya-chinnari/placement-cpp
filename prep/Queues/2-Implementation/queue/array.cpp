#include <bits/stdc++.h>
using namespace std;

class Queue
{
   int *arr;
   int front;
   int rear;
   int size;

public:
   Queue()
   {
      size = 1000;
      arr = new int[size];
      // keep front and back at arr[0]
      front = 0;
      rear = 0;
   }

   void enqueue(int data)
   {
      if (rear == size)
      {
         cout << "Queue is full" << endl;
      }
      else
      {
         arr[rear] = data;
         rear++;
      }
   }

   int dequeue()
   {
      if (front == rear)
      {
         cout << "Queue is empty" << endl;
         return -1;
      }
      else
      {
         arr[front] = -1;
         front++;
         if (front == rear)
         {
            front = 0;
            rear = 0;
         }
      }
   }

   bool isEmpty()
   {
   }

}

int
main()
{

   return 0;
}