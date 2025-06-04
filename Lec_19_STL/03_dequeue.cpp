#include <iostream>
#include <deque> // Include deque header
using namespace std;

int main()
{
   // Create an empty deque of integers
   deque<int> dq;

   // ********* INSERTION OPERATIONS *********
   dq.push_back(10);  // Insert 10 at the back
   dq.push_front(20); // Insert 20 at the front
   dq.push_back(30);  // Insert 30 at the back
   dq.push_front(40); // Insert 40 at the front

   cout << "Deque after push operations: ";
   for (int val : dq)
      cout << val << " "; // 40 20 10 30
   cout << endl;

   // ********* ACCESSING ELEMENTS *********
   cout << "Front element: " << dq.front() << endl;    // 40
   cout << "Back element: " << dq.back() << endl;      // 30
   cout << "Element at index 2: " << dq.at(2) << endl; // 10

   // ********* SIZE AND EMPTY *********
   cout << "Size of deque: " << dq.size() << endl; // 4
   cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

   // ********* DELETION OPERATIONS *********
   dq.pop_front(); // Removes 40
   dq.pop_back();  // Removes 30

   cout << "Deque after pop operations: ";
   for (int val : dq)
      cout << val << " "; // 20 10
   cout << endl;

   // ********* INSERT AT SPECIFIC POSITION *********
   auto it = dq.begin();  // Get iterator to the beginning (points to element 0)
   dq.insert(it + 1, 99); // Insert 99 at position 1 (second position)
   cout << "After inserting 99 at position 1: ";
   for (int val : dq)
      cout << val << " "; // e.g., if deque was 20 10 → now 20 99 10
   cout << endl;

   // ********* ERASE ELEMENTS *********
   dq.erase(dq.begin() + 1); // Erase element at position 1 (which is 99 now)
   cout << "After erasing element at position 1: ";
   for (int val : dq)
      cout << val << " "; // Should output: 20 10
   cout << endl;

   // ********* ERASE FIRST ELEMENT USING RANGE *********
   deque<int> dq1 = {100, 200, 300, 400};

   cout << "[dq1] : Original deque: ";
   for (int val : dq1)
      cout << val << " ";
   cout << endl;

   // Erase first element using range
   dq1.erase(dq1.begin(), dq1.begin() + 1); // Removes 100

   cout << "[dq1] : After erasing first element using range: ";
   for (int val : dq1)
      cout << val << " "; // Expected: 200 300 400
   cout << endl;

   // ********* CLEAR THE DEQUE *********
   dq.clear(); // Removes all elements
   cout << "Deque cleared. Size is now: " << dq.size() << endl;

   // ********* ASSIGN NEW VALUES *********
   dq.assign(5, 7); // Fill deque with five 7s
   cout << "Deque after assign(5, 7): ";
   for (int val : dq)
      cout << val << " "; // 7 7 7 7 7
   cout << endl;

   // ********* SWAP OPERATION *********
   deque<int> dq2 = {1, 2, 3};
   dq.swap(dq2); // Swap dq with dq2
   cout << "Deque after swap with dq2: " << endl;
   cout << " dq: ";
   for (int val : dq)
      cout
          << val << " "; // 1 2 3
   cout << endl;

   // ********* USING RANGE-BASED LOOP *********
   cout << "Final deque (dq2 contents): ";
   for (int val : dq2)
      cout << val << " "; // 7 7 7 7 7
   cout << endl;

   return 0;
}
