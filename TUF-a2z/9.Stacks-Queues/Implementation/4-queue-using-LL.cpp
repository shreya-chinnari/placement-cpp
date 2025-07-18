#include <iostream>
using namespace std;

// Singly linked list node for the queue
struct Node
{
   int data;
   Node *next;
   Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
private:
   Node *start; // Points to top node
   Node *end;   // Points to rear node
   int count;   // Tracks current size

public:
   // Constructor: Initializes queue empty
   Queue() : start(nullptr), end(nullptr), count(0) {}

   // Destructor: Frees all nodes to avoid memory leak
   ~Queue()
   {
      while (!isEmpty())
      {
         dequeue();
      }
   }

   // Enqueue (push): O(1) — add to rear
   bool enqueue(int value)
   {
      Node *temp = new (nothrow) Node(value);
      // if (!temp)
      // {
      //    cout << "Memory allocation failed. Queue Overflow\n";
      //    return false;
      // }
      // if (isEmpty())
      if (start == nullptr)
      {
         start = end = temp;
      }
      else
      {
         end->next = temp;
         end = temp;
      }
      ++count;
      return true;
   }

   // Dequeue (pop): O(1) — remove from top
   bool dequeue()
   {
      if (start == nullptr)
      {
         cout << "Queue Underflow\n";
         return false;
      }
      Node *temp = start;
      start = start->next;
      if (!start)
         end = nullptr; // Empty queue after removal
      delete temp;
      --count;
      return true;
   }

   // Peek at top element: O(1)
   int top() const
   {
      if (isEmpty())
      {
         cout << "Queue is empty\n";
         return -1;
      }
      return start->data;
   }

   // Get current queue size
   int size() const
   {
      return count;
   }

   // Is the queue empty?
   bool isEmpty() const
   {
      return start == nullptr;
   }

   // Is the queue full? (Linked list based queue is full only if system is out of memory)
   bool isFull() const
   {
      return false;
   }
};

// Example usage
int main()
{
   Queue q;
   q.enqueue(10);
   q.push(20);
   q.enqueue(30);
   cout << "top: " << q.top() << endl; // 10
   q.dequeue();
   cout << "top: " << q.top() << endl;   // 20
   cout << "Size: " << q.size() << endl; // 2
   cout << "isEmpty? " << (q.isEmpty() ? "Yes" : "No") << endl;
   cout << "isFull? " << (q.isFull() ? "Yes" : "No") << endl;
   q.pop();
   q.pop(); // Underflow test
   return 0;
}
