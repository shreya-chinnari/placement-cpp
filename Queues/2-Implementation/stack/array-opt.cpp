#include <iostream>
using namespace std;

class Stack
{
   int capacity; // Maximum capacity of stack (grows dynamically)
   int *arr;     // Pointer to dynamically allocated array
   int topIndex; // Index of top element (-1 means empty)

public:
   // Constructor
   Stack(int initialSize = 2)
   {
      capacity = initialSize;  // Start with small capacity
      arr = new int[capacity]; // Allocate memory
      topIndex = -1;           // Empty stack
   }

   // Destructor (free memory)
   ~Stack()
   {
      delete[] arr;
   }

   // Push operation (with resizing if needed)
   void push(int x)
   {
      if (topIndex == capacity - 1)
      {
         // Stack overflow → double the capacity
         cout << "Resizing stack from " << capacity << " to " << capacity * 2 << endl;
         int *newArr = new int[capacity * 2];
         for (int i = 0; i < capacity; i++)
         {
            newArr[i] = arr[i]; // Copy old elements
         }
         delete[] arr; // Free old memory
         arr = newArr;
         capacity *= 2;
      }
      arr[++topIndex] = x;
   }

   // Pop operation (with underflow check)
   int pop()
   {
      if (isEmpty())
      {
         cout << "Stack Underflow! Cannot pop from empty stack." << endl;
         return -1; // Error code
      }
      return arr[topIndex--];
   }

   // Get top element (with underflow check)
   int top()
   {
      if (isEmpty())
      {
         cout << "Stack is empty! No top element." << endl;
         return -1;
      }
      return arr[topIndex];
   }

   // Get current size
   int size()
   {
      return topIndex + 1;
   }

   // Check if stack is empty
   bool isEmpty()
   {
      return topIndex == -1;
   }
};
int main()
{

   Stack s;
   s.push(6);
   s.push(3);
   s.push(7);
   cout << "Top of stack is before deleting any element " << s.top() << endl;
   cout << "Size of stack before deleting any element " << s.size() << endl;
   cout << "The element deleted is " << s.pop() << endl;
   cout << "Size of stack after deleting an element " << s.size() << endl;
   cout << "Top of stack after deleting an element " << s.top() << endl;
   return 0;
}