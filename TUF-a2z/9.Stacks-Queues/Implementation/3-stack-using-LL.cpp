#include <iostream>
using namespace std;

// Node structure for singly linked list ----------------
struct Node
{
   int data;   // Stores the value for this stack node.
   Node *next; // Pointer to the next node in the stack

   Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node with value and next {null} pointer
};

// Implements the stack structure and logic -------------
class Stack
{
private:
   Node *head; // Points to top of stack [head = top]
   int count;  // Tracks current size

public:
   // Constructor: Initializes stack
   Stack() : head(nullptr), count(0) {}

   // Destructor: Frees all nodes to avoid memory leaks
   ~Stack()
   {
      while (head)
      {
         pop();
      }
   }

   // Push: Insert element at the top (O(1))
   bool push(int value)
   {
      Node *temp = new (nothrow) Node(value); // If allocation fails (e.g., out of RAM), it returns nullptr instead of throwing a std::bad_alloc exception.
      if (!temp)
      {
         cout << "Memory allocation failed. Stack Overflow\n";
         return false;
      }
      temp->next = head;
      head = temp;
      ++count;
      return true;
   }

   // Pop: Remove the top element (O(1))
   bool pop()
   {
      if (isEmpty())
      {
         cout << "Stack Underflow\n";
         return false;
      }
      Node *temp = head;
      head = head->next;
      delete temp;
      --count;
      return true;
   }

   // Top: Get the value at the top (O(1))
   int top() const
   {
      if (isEmpty())
      {
         cout << "Stack is empty\n";
         return -1; // Alternatively, throw exception for production
      }
      return head->data;
   }

   // Size: Return number of elements
   int size() const
   {
      return count;
   }

   // isEmpty: Check if stack is empty
   bool isEmpty() const
   {
      return head == nullptr;
   }

   // isFull: For linked list, stack only full if memory exhausted
   bool isFull() const
   {
      return false; // Linked list stack rarely "full"
   }
};

// Example usage
int main()
{
   Stack s;
   s.push(10);
   s.push(20);
   cout << "Top: " << s.top() << endl; // Should print 20
   s.pop();
   cout << "Top: " << s.top() << endl;   // Should print 10
   cout << "Size: " << s.size() << endl; // Should print 1
   cout << "isEmpty? " << (s.isEmpty() ? "Yes" : "No") << endl;
   cout << "isFull? " << (s.isFull() ? "Yes" : "No") << endl;
   s.pop();
   s.pop(); // Underflow test
   return 0;
}
