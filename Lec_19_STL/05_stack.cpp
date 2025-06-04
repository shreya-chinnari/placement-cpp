#include <iostream>
#include <stack> // Required for std::stack

using namespace std;

// "stack" is a [LIFO (Last In First Out)] implementation in C++ STL.
// It allows you to add and remove elements in a last-in-first-out manner.
// It is not a sequence container like vector or list, but rather an adapter that uses another container (like deque or vector) to provide stack functionality.
// A stack is dynamic because it can grow and shrink in size as elements are added or removed.
// It is particularly useful for algorithms that require backtracking or maintaining a history of operations, such as depth-first search in graphs or expression evaluation.

int main()
{
   // Declare a stack of integers named 's'
   stack<int> s;

   // Push elements onto the stack
   s.push(10); // Push 10 to the top of the stack
   s.push(20); // Push 20 to the top of the stack
   s.push(30); // Push 30 to the top of the stack

   // Display the top element
   cout << "Top element: " << s.top() << endl; // Outputs 30

   // Pop the top element
   s.pop();                                      // Removes the top element (30)
   cout << "Top after pop: " << s.top() << endl; // Outputs 20

   // Check if the stack is empty
   if (s.empty())
   {
      cout << "Stack is empty" << endl;
   }
   else
   {
      cout << "Stack is not empty" << endl;
   }

   // Get the size of the stack
   cout << "Stack size: " << s.size() << endl; // Outputs 2

   // Access and pop all elements using a loop
   cout << "Stack elements (from top to bottom): ";
   while (!s.empty())
   {
      cout << s.top() << " "; // Print top element
      s.pop();                // Remove top element
   }
   cout << endl;

   // After popping all elements, stack should be empty
   cout << "Is stack empty now? " << (s.empty() ? "Yes" : "No") << endl;

   return 0;
}
