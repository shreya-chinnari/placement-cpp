#include <iostream>
using namespace std;

// TC : O()
// SC : O()

int main()
{

   return 0;
}

/*
    Helper function to maintain queue order.
    - If s2 is empty, move all elements from s1 to s2.
    - This reverses the order: the oldest element pushed to s1
      comes to the top of s2, ready to be dequeued.
    - Amortized O(1) cost for queue operations.
*/
void shiftStacks()
{
   if (s2.empty())
   { // Only transfer if s2 is empty

      // while (!s1.empty())
      while (s1.size())
      {                     // Move all elements from s1 to s2
         s2.push(s1.top()); // The oldest element ends up at the top of s2
         s1.pop();
      }
   }
}

public:
// Enqueue: Add a new element to the end of the queue.
// - Always push onto s1.
void enqueue(int value)
{
   s1.push(value);
}

/*
    Dequeue: Remove and return the front (oldest) element from the queue.
    - If both stacks are empty, the queue is empty (underflow).
    - If s2 is empty, transfer elements from s1 so the oldest is on top.
    - Pop and return the top of s2.
*/
int dequeue()
{
   shiftStacks(); // Ensure s2 has front element on top
   if (s2.empty())
   {
      cout << "Queue Underflow\n";
      return -1;
   }
   int res = s2.top();
   s2.pop();
   return res;
}

/*
    Peek/Front: Get the value at the front of the queue without removing.
    - Works the same as dequeue but does not pop.
*/
int front()
{
   shiftStacks();
   if (s2.empty())
   {
      cout << "Queue is empty\n";
      return -1;
   }
   return s2.top();
}

// isEmpty: Return true if queue has no elements in either stack.
bool isEmpty() const
{
   return s1.empty() && s2.empty();
}

// size: Return total number of elements currently stored in the queue.
int size() const
{
   return static_cast<int>(s1.size() + s2.size());
}
}
;

int main()
{
   Queue q;

   // Enqueue some elements
   q.enqueue(10); // Queue: 10
   q.enqueue(20); // Queue: 10, 20

   cout << "Front: " << q.front() << endl; // Should print 10

   q.enqueue(30); // Queue: 10, 20, 30

   cout << "Dequeue: " << q.dequeue() << endl; // Should remove and print 10

   cout << "Front: " << q.front() << endl; // Should print 20

   cout << "Size: " << q.size() << endl; // Should print 2 (20, 30 remain)

   cout << "isEmpty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print "No"

   q.dequeue(); // Removes 20
   q.dequeue(); // Removes 30

   q.dequeue(); // Underflow test: queue is empty, prints message

   return 0;
}
