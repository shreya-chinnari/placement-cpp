#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack
{
   stack<long long> st; // Stores actual or encoded values
   long long mini;      // Keeps track of the minimum value at any point

public:
   // Constructor
   MinStack()
   {
      while (!st.empty())
         st.pop();    // Clean start (just in case)
      mini = INT_MAX; // Initialize mini with a very large value
   }

   // Pushes a value onto the stack
   void push(int value)
   {
      long long val = value; // Promote to long long to prevent overflow during encoding

      if (st.empty())
      {
         // First element: set it as the minimum
         mini = val;
         st.push(val);
      }
      else
      {
         if (val < mini)
         {
            // Encode and store a special value when new val < current min
            // Formula: 2 * val - mini — this encodes previous mini in disguise
            st.push(2 * val - mini);
            mini = val; // Update mini to new smaller value
         }
         else
         {
            st.push(val); // Just push normally
         }
      }
   }

   // Removes the top element
   void pop()
   {
      if (st.empty())
         return;

      long long el = st.top();
      st.pop();

      if (el < mini)
      {
         // If the popped element is an encoded value:
         // Recover the previous minimum using inverse formula
         mini = 2 * mini - el;
      }
      // Otherwise, no change to mini
   }

   // Returns the top element (decoded if necessary)
   int top()
   {
      if (st.empty())
         return -1;

      long long el = st.top();

      if (el < mini)
      {
         // Top is an encoded value => actual top is current mini
         return mini;
      }
      return el; // Normal value
   }

   // Returns the current minimum in O(1)
   int getMin()
   {
      return mini;
   }
};

int main()
{
   MinStack st;

   // Push 12
   st.push(12);
   cout << "Pushed 12\n";

   // Push 15
   st.push(15);
   cout << "Pushed 15\n";

   // Push 10
   st.push(10);
   cout << "Pushed 10\n";

   // Top
   cout << "Top: " << st.top() << endl; // Should be 10

   // GetMin
   cout << "Min: " << st.getMin() << endl; // Should be 10

   // Pop
   st.pop();
   cout << "Popped\n";

   // Top
   cout << "Top: " << st.top() << endl; // Should be 15

   // GetMin
   cout << "Min: " << st.getMin() << endl; // Should be 12

   // Push 10
   st.push(10);
   cout << "Pushed 10\n";

   // Top
   cout << "Top: " << st.top() << endl; // Should be 10

   // GetMin
   cout << "Min: " << st.getMin() << endl; // Should be 10

   // Pop
   st.pop();
   cout << "Popped\n";

   // Top
   cout << "Top: " << st.top() << endl; // Should be 15

   return 0;
}