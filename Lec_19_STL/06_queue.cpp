#include <iostream>
#include <queue> // Required for queue
using namespace std;

// "queue" is a [FIFO (First In First Out)] implementation in C++ STL.
// It allows you to add and remove elements in a first-in-first-out manner.
// It is not a sequence container like vector or list, but rather an adapter that uses another container (like deque or list) to provide queue functionality.
// A queue is dynamic because it can grow and shrink in size as elements are added or removed.
// It is a non-constant time complexity container, meaning that the time taken to perform operations like push and pop can vary based on the underlying container used.
// It is particularly useful for algorithms that require processing elements in the order they were added, such as breadth-first search in graphs or task scheduling.

int main()
{
   // Declare a queue of integers named q
   queue<int> q;

   // 1. push(x) – Add an element to the back of the queue
   q.push(10);
   q.push(20);
   q.push(30);
   cout << "After pushing 10, 20, 30:" << endl;
   cout << '\n';

   // 2. front() – Get the front element of the queue
   cout << "Front element: " << q.front() << endl;

   // 3. back() – Get the last (rear) element of the queue
   cout << "Back element: " << q.back() << endl;

   // 4. size() – Get the number of elements in the queue
   cout << "Size of queue: " << q.size() << endl;

   // 5. empty() – Check whether the queue is empty
   cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
   cout << '\n';

   // 6. pop() – Remove the front element from the queue
   q.pop(); // Removes 10
   cout << "After popping one element:" << endl;
   cout << '\n';
   cout << "Front element: " << q.front() << endl;
   cout << "Size of queue: " << q.size() << endl;

   // Loop to display all elements (note: queue doesn't support iterators)
   cout << "Remaining elements in queue: ";
   while (!q.empty())
   {
      cout << q.front() << " "; // Access the front
      q.pop();                  // Remove the front
   }
   cout << endl;

   // 7. Refill queue and clear it manually (optional utility)
   q.push(100);
   q.push(200);
   q.push(300);
   cout << '\n';
   cout << "New queue: ";
   while (!q.empty())
   {
      cout << q.front() << " "; // Access the front
      q.pop();                  // Remove the front
   }
   cout << endl;

   // Clearing queue manually (no built-in clear() function in std::queue)
   cout << "Clearing queue manually..." << endl;
   while (!q.empty())
   {
      q.pop();
   }
   cout << "Queue cleared. Size now: " << q.size() << endl;

   return 0;
}
