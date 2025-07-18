// Approach 2 : push() : O(1), pop() : O(n)

#include <iostream>
#include <stack>
using namespace std;

/*
    Queue class using two stacks.
    - s1: Used for enqueue (push).
    - s2: Used for dequeue (pop) and to access the front (top).
    The order is preserved by shifting elements from s1 to s2 only when needed.
*/
class Queue
{
private:
   stack<int> s1; // Stack for incoming (pushed) elements
   stack<int> s2; // Stack for outgoing (to be popped) elements

public:
   // Enqueue (push): Add item to the queue (O(1) always)
   void push(int x)
   {
      s1.push(x);
      // No expensive operations here:
      // Element added straight to s1, no transfers occur during push.
   }

   // Dequeue (pop): Remove the front (oldest) element (O(1) amortized)
   void pop()
   {
      // If s2 is not empty, pop directly
      if (!s2.empty())
      {
         s2.pop();
      }

      else
      {
         if (s1.empty())
         {
            cout << "Queue Underflow\n";
            return;
         }
         while (s1.size())
         {
            s2.push(s1.top());
            s1.pop();
         }
         s2.pop(); // Now pop from s2, which has the oldest element on top
      }
   }

   /*
   alternate pop() implementation:



     // Queue pop based on two-stack logic
    void pop() {
        // If s2 is not empty, pop directly
        if (!s2.empty()) {
            s2.pop();
            return;
        }
        // If s2 is empty, move elements from s1 to s2 except for the last one
        if (s1.empty()) {
            // Queue is empty
            return;
        }
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        // Remove the last element from s1 (the queue front)
        s1.pop();
    }


   */

   // top(): Return the front (oldest) element (O(n) if shift needed)
   int top()
   {
      if (!s2.empty())
      {
         return s2.top();
      }
      if (s1.empty())
      {
         cout << "Queue is empty\n";
         return -1;
      }
      // Move all from s1 to s2 if needed to access the front
      while (!s1.empty())
      {
         s2.push(s1.top());
         s1.pop();
      }
      return s2.top();
   }

   // isEmpty(): Check if queue is empty (O(1))
   bool isEmpty()
   {
      return s1.empty() && s2.empty();
   }

   // isFull(): This implementation uses dynamic memory, so always false (unless memory exhausted)
   bool isFull()
   {
      return false;
   }

   // size(): Return total number of elements (O(1))
   int size()
   {
      return static_cast<int>(s1.size() + s2.size());
   }
};

int main()
{
   Queue q;

   cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;

   q.push(10);
   q.push(20);
   q.push(30);

   cout << "Queue size: " << q.size() << endl; // Should print 3
   cout << "Front/top: " << q.top() << endl;   // Should print 10

   q.pop();
   cout << "Front/top after pop: " << q.top() << endl; // Should print 20
   cout << "Queue size: " << q.size() << endl;         // Should print 2

   q.push(100);
   cout << "Queue size after push: " << q.size() << endl; // Should print 3
   cout << "Front/top: " << q.top() << endl;              // Should print 20

   while (!q.isEmpty())
   {
      cout << "Popping front: " << q.top() << endl;
      q.pop();
   }

   cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
   cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;

   // Try pop/top from empty for underflow message
   q.pop();
   cout << "Top after final pop: " << q.top() << endl;

   return 0;
}
