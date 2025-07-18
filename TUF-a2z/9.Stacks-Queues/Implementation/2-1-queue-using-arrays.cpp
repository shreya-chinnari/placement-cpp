#include <iostream>
using namespace std;

class Queue
{
private:
   int size;  // total capacity
   int *arr;  // array for storing elements
   int front; // index of front element
   int rear;  // index to insert next element
   int count; // current element count

public:
   // Constructor using constructor initializer list
   Queue(int sz) : size(sz), front(0), rear(0), count(0)
   {
      arr = new int[size];
   }

   // Destructor to free allocated memory
   ~Queue() { delete[] arr; }

   // Standard enqueue operation
   bool enqueue(int value)
   {
      if (count == size)
      {
         cout << "Queue Overflow\n";
         return false;
      }
      arr[rear] = value;
      rear = (rear + 1) % size;
      ++count;
      return true;
   }

   // Synonym: push is the same as enqueue
   bool push(int value) { return enqueue(value); }

   // Standard dequeue operation
   bool dequeue()
   {
      if (count == 0)
      {
         cout << "Queue Underflow\n";
         return false;
      }
      front = (front + 1) % size;
      --count;
      return true;
   }

   // Synonym: pop is the same as dequeue
   bool pop() { return dequeue(); }

   // Standard peek operation
   int peek()
   {
      if (count == 0)
      {
         cout << "Queue is empty\n";
         return -1;
      }
      return arr[front];
   }

   // Synonym: top is the same as peek
   int top() { return peek(); }

   // Check if queue is empty
   bool empty() { return count == 0; }

   // Synonym: isEmpty
   bool isEmpty() { return empty(); }

   // Check if queue is full
   bool full() { return count == size; }

   // Synonym: isFull
   bool isFull() { return full(); }

   // Return current size of the queue
   int getSize() { return count; }

   // Synonym: size()
   int size_() { return count; } // named size_ to avoid confusion with 'size' member
   int size() { return count; }
};

int main()
{
   Queue q(5);
   q.push(10);
   q.push(20);
   cout << "Top: " << q.top() << endl; // Front element (10)
   q.pop();
   cout << "Top: " << q.top() << endl;   // Front element (20)
   cout << "Size: " << q.size() << endl; // Should be 1
   cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
   cout << "Is full? " << (q.isFull() ? "Yes" : "No") << endl;

   // Fill the queue, demonstrate isFull
   q.push(30);
   q.push(40);
   q.push(50);
   q.push(60); // triggers overflow
   cout << "Is full? " << (q.isFull() ? "Yes" : "No") << endl;
   cout << "Current queue size: " << q.size() << endl;
   return 0;
}
