#include <iostream>
#include <queue>
using namespace std;

/*
    Stack class implemented using only a single queue.
    This simulates LIFO (Last-In-First-Out) stack behavior with queue operations.
*/
class Stack
{
private:
   queue<int> q; // Only one standard queue to hold the elements

public:
   // Pushes an element onto the stack (O(n) time)
   void push(int x)
   {
      int s = q.size(); // Save current size of queue before push

      q.push(x); // Insert new element at the end (normal queue behavior)

      // To simulate a stack's LIFO behavior,
      // we need to ensure the most recently pushed element is always at the front of the queue.
      // So, rotate all the previous elements behind this new one:
      for (int i = 0; i < s; ++i)
      {
         // - Take element from the front and push it to the back.
         // - Repeat this for the count of elements that were already in the queue before the new push.
         q.push(q.front());
         q.pop();
      }
      // After this rotation, the newly pushed element is now at the front of the queue,
      // so any pop or top operation will access it first, mimicking stack behavior.
   }

   // Removes (pops) the top element from the stack (O(1) time)
   void pop()
   {
      if (q.empty())
      {
         cout << "Stack Underflow\n"; // Cannot pop if stack is empty
         return;
      }
      q.pop(); // Removes the front element, which is the top of stack
   }

   // Returns the top element of the stack (O(1) time)
   int top()
   {
      if (q.empty())
      {
         cout << "Stack is empty\n"; // No element to return
         return -1;
      }
      return q.front(); // The front of the queue is treated as the top of the stack
   }

   // Returns the number of elements in the stack
   int size()
   {
      return q.size();
   }

   // Returns true if the stack is empty, false otherwise
   bool isEmpty()
   {
      return q.empty();
   }

   // Returns true if the stack is full
   // (Always false here; std::queue grows dynamically and isn't limited like a fixed array)
   bool isFull()
   {
      return false;
   }
};

// Example usage
int main()
{
   Stack st;
   st.push(10); // [10]
   st.push(20); // [20, 10]
   st.push(30); // [30, 20, 10]  // Most recent push is always at front

   cout << "Top: " << st.top() << endl; // Should print 30

   st.pop(); // Removes 30

   cout << "Top: " << st.top() << endl;                          // Should print 20
   cout << "Size: " << st.size() << endl;                        // Should print 2
   cout << "isEmpty? " << (st.isEmpty() ? "Yes" : "No") << endl; // "No"
   cout << "isFull? " << (st.isFull() ? "Yes" : "No") << endl;   // "No"

   return 0;
}

// push() – O(n): Must rotate the old contents each time you add a new element.

// pop() / top() – O(1) : Always just pop or return front.
