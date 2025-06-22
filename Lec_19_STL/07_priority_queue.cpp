#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

using namespace std;

// "priority_queue" is a [heap-based] implementation in C++ STL.
// It allows you to access the largest (or smallest) element efficiently.
// It is implemented as a binary heap, which is a complete binary tree.

// priority queue is an adapter that uses a container (like vector) to provide priority queue functionality.
// The default behavior is to create a max-heap, where the largest element is at the top.

// A priority queue is dynamic because it can grow and shrink in size as elements are added or removed.
// It is a non-constant time complexity container, meaning that the time taken to perform operations like push and pop can vary based on the number of elements in the queue.

// max-heap is particularly useful for algorithms that require processing elements in order of priority, such as Dijkstra's algorithm for shortest paths or Huffman coding for data compression.
// min-heap can be used for similar purposes but with the smallest element at the top, which is useful in scenarios like scheduling tasks with the least time first.

int main()
{
   // 1. Declaration of a max-heap priority queue (default behavior)
   // Stores integers with largest element at the top
   priority_queue<int> pq;

   // 2. Inserting elements into the priority queue
   pq.push(10);
   pq.push(30);
   pq.push(20);
   pq.push(5);
   pq.push(1);

   // 3. Accessing the top element (largest element for max-heap)
   cout << "Top element (max): " << pq.top() << endl; // Should print 30

   // 4. Removing the top element
   pq.pop(); // Removes 30

   cout << "After pop, new top element: " << pq.top() << endl; // Should print 20

   // 5. Checking if the priority queue is empty
   if (!pq.empty())
   {
      cout << "Priority queue is not empty." << endl;
   }

   // 6. Getting the size of the priority queue
   cout << "Size of priority queue: " << pq.size() << endl;

   // 7. Removing all elements (by popping one by one)
   cout << "Removing all elements:" << endl;
   while (!pq.empty())
   {
      cout << pq.top() << " ";
      pq.pop();
   }
   cout << endl;

   // 8. Declaration of a min-heap priority queue using greater<int>
   // Stores integers with smallest element at the top
   priority_queue<int, vector<int>, greater<int>> min_pq;

   min_pq.push(10);
   min_pq.push(30);
   min_pq.push(20);
   min_pq.push(5);
   min_pq.push(1);
   cout << endl;
   cout << "Elements inserted into min-heap priority queue." << endl;
   cout << "Top element (min): " << min_pq.top() << endl; // Should print 1

   // 9. Demonstrate pop and top with min-heap
   min_pq.pop();                                                   // Removes 1
   cout << "After pop, new top element: " << min_pq.top() << endl; // Should print 5

   return 0;
}
