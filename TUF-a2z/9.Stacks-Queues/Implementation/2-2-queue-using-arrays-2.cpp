#include <iostream>
using namespace std;

class Queue
{
private:
   int size;
   int *q;
   int curSize;
   int start;
   int end;

public:
   // Constructor to initialize the queue
   Queue(int s = 10)
   {
      size = s;
      q = new int[size];
      curSize = 0;
      start = -1;
      end = -1;
   }

   // Destructor to free allocated memory
   ~Queue()
   {
      delete[] q;
   }

   // Push (enqueue) operation
   bool push(int n)
   {
      // Check if queue is full
      if (curSize >= size)
      {
         cout << "Queue is full!\n";
         return false;
      }
      // Handle queue empty case
      if (curSize == 0)
      {
         start = end = 0;
      }
      else
      {
         end = (end + 1) % size; // To support wrapping for circular queue
      }
      q[end] = n;
      curSize++;
      return true;
   }

   // Pop (dequeue) operation
   bool pop()
   {
      // Check if queue is empty
      if (curSize == 0)
      {
         cout << "Queue is empty!\n";
         return false;
      }
      // Only one element left
      if (curSize == 1)
      {
         start = end = -1;
      }
      else
      {
         start = (start + 1) % size;
      }
      curSize--;
      return true;
   }

   // Get the element at the front of the queue
   int front()
   {
      if (curSize == 0)
      {
         cout << "Queue is empty!\n";
         return -1;
      }
      return q[start];
   }

   // Get the number of elements in the queue
   int length()
   {
      return curSize;
   }

   // Check if queue is empty
   bool empty()
   {
      return curSize == 0;
   }

   // Check if queue is full
   bool full()
   {
      return curSize == size;
   }
};

// Example usage
int main()
{
   Queue q(5);

   q.push(1); // Add 1
   q.push(2); // Add 2
   q.push(3); // Add 3

   cout << "Front: " << q.front() << endl; // Should print 1

   q.pop();                                // Remove 1 (front)
   cout << "Front: " << q.front() << endl; // Should print 2

   q.push(4);
   q.push(5);
   q.push(6); // Should succeed, as we popped one

   cout << "Is full? " << (q.full() ? "Yes" : "No") << endl;
   cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

   while (!q.empty())
   {
      cout << q.front() << " ";
      q.pop();
   }
   cout << endl;

   return 0;
}
