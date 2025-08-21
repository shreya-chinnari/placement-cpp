#include <bits/stdc++.h>
using namespace std;

class Stack
{
   static const int MAX = 1000; // Maximum stack size (fixed at compile time)
   int arr[MAX];                // Static array to store elements
   int top;                     // Index of top element (-1 means empty)

public:
   // Constructor
   Stack()
   {
      top = -1; // initially empty
   }

   // Push element onto stack
   void push(int x)
   {
      if (top == MAX - 1)
      { // check overflow
         cout << "Stack Overflow! Cannot push " << x << endl;
         return;
      }
      arr[++top] = x;
   }

   // Pop element from stack
   int pop()
   {
      if (isEmpty())
      { // underflow
         cout << "Stack Underflow! Cannot pop from empty stack." << endl;
         return -1;
      }
      return arr[top--];
   }

   // Get top element
   int Top()
   {
      if (isEmpty())
      {
         cout << "Stack is empty! No top element." << endl;
         return -1;
      }
      return arr[top];
   }

   // Get current size
   int Size()
   {
      return top + 1;
   }

   // Check if stack is empty
   bool isEmpty()
   {
      return top == -1;
   }
};

int main()
{
   Stack s;

   s.push(6);
   s.push(3);
   s.push(7);

   cout << "Top of stack before deleting any element: " << s.Top() << endl;
   cout << "Size of stack before deleting any element: " << s.Size() << endl;

   cout << "The element deleted is: " << s.pop() << endl;

   cout << "Size of stack after deleting an element: " << s.Size() << endl;
   cout << "Top of stack after deleting an element: " << s.Top() << endl;

   return 0;
}
