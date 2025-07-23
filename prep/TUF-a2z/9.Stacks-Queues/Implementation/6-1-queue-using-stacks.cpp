// Approach 1 : push() : O(2n), pop() : O(1)

#include <iostream>
#include <stack>
using namespace std;

/*
    Queue implemented using two stacks.
    This structure preserves FIFO (First-In-First-Out) behavior
    using two LIFO (Last-In-First-Out) stacks.
*/

class Queue
{
private:
   stack<int> s1; // Stack where new elements are pushed (rear of queue)
   stack<int> s2; // Stack from which elements are popped/peeked (front of queue)

public:
   // Enqueue (push) operation: Inserts element at the rear of the queue
   void push(int x)
   {
      // STEP 1 : Move all elements from s1 to s2, reversing their order
      while (s1.size()) // while (!s1.empty())
      {
         s2.push(s1.top());
         s1.pop();
      }

      // STEP 2 : Push the new element to the now-empty s1
      s1.push(x);

      // STEP 3 : Move all elements back from s2 to s1, restoring original order behind the new element
      while (s2.size())
      {
         s1.push(s2.top());
         s2.pop();
      }
      // ** After this: s1's top is always the queue's front, bottom is the rear
   }

   // Dequeue (pop) operation: Removes the front element (FIFO)
   void pop()
   {
      if (s1.empty())
      {
         cout << "Queue Underflow\n";
         return;
      }
      // The top of s1 is always the oldest inserted element ("front" of queue)
      s1.pop();
   }

   // Return the front element (oldest in queue)
   int front()
   {
      if (s1.empty())
      {
         cout << "Queue is empty\n";
         return -1;
      }
      return s1.top();
   }

   // Return the 'top' (rear, last element inserted) of the queue
   int top()
   {
      if (s1.empty())
      {
         cout << "Queue is empty\n";
         return -1;
      }
      // Move all except the bottom element to s2
      while (s1.size() > 1)
      {
         s2.push(s1.top());
         s1.pop();
      }
      int last = s1.top(); // This is the bottom/rear element
      s2.push(s1.top());
      s1.pop();
      // Restore all to s1
      while (!s2.empty())
      {
         s1.push(s2.top());
         s2.pop();
      }
      return last;
   }

   // Return true if the queue is empty
   bool isEmpty()
   {
      return s1.empty();
   }

   // Return the number of elements in the queue
   int size()
   {
      return s1.size();
   }
};

int main()
{
   Queue q;
   q.push(10); // Queue: 10
   q.push(20); // Queue: 10, 20
   q.push(30); // Queue: 10, 20, 30 (front is 10)

   cout << "Front: " << q.front() << endl; // Should print 10
   q.pop();                                // Removes 10

   cout << "Front: " << q.front() << endl; // Should print 20

   q.push(40); // Queue: 20, 30, 40

   cout << "Queue Size: " << q.size() << endl; // Should be 3

   cout << "Top: " << q.top() << endl; // Prints rear (most recent)

   while (!q.isEmpty())
   { // Print all elements in order
      cout << q.front() << " ";
      q.pop();
   }
   cout << endl;

   cout << "Top: " << q.top() << endl; // Prints rear (most recent)

   q.pop(); // Underflow test - pops from empty

   return 0;
}
