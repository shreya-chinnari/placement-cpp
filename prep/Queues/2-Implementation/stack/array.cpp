#include <bits/stdc++.h>
using namespace std;

class Stack
{            // Define a class named Stack
   int size; // Variable to store maximum size of stack
   int *arr; // Pointer to dynamically allocated array for stack elements
   int top;  // Index of the current top element (-1 means empty)

public: // Public access specifier (members below are accessible outside)
        // Constructor
   Stack()
   {                       // Constructor: initializes a new Stack object
      top = -1;            // Initially, stack is empty so top is set to -1
      size = 1000;         // Default maximum size of the stack is 1000
      arr = new int[size]; // Dynamically allocate an array of integers of given size
   }

   // Destructor (free memory)
   ~Stack()
   {
      delete[] arr;
   }

   void push(int x)
   {
      top++;
      arr[top] = x;
   }

   int pop()
   {
      if (isEmpty())
      {
         cout << "Stack Underflow! Cannot pop from empty stack." << endl;
         return -1;
      }
      return arr[topIndex--];
   }

   int Top()
   {
      if (isEmpty())
      {
         cout << "Stack is empty! No top element." << endl;
         return -1;
      }
      return arr[topIndex];
   }
   int Size()
   {
      return top + 1;
   }
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
   cout << "Top of stack is before deleting any element " << s.Top() << endl;
   cout << "Size of stack before deleting any element " << s.Size() << endl;
   cout << "The element deleted is " << s.pop() << endl;
   cout << "Size of stack after deleting an element " << s.Size() << endl;
   cout << "Top of stack after deleting an element " << s.Top() << endl;
   return 0;
}