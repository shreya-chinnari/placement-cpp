#include <iostream>
#include <vector>
#include <algorithm> // for reverse, count, rotate, sort
using namespace std;

// Utility function to print vector contents
void printVector(const vector<int> &v)
{
   for (int x : v)
      cout << x << " ";
   cout << "\n";
}

int main()
{
   // Initialize a vector
   vector<int> v = {10, 20, 30, 40, 50};
   cout << "Original vector: ";
   printVector(v);

   // 1) swap two elements (swaps values of v[1] and v[3])
   cout << "\n1) Swap elements at index 1 and 3:\n";
   cout << "Before swap: ";
   printVector(v);
   swap(v[1], v[3]); // swap 20 and 40
   cout << "After swap:  ";
   printVector(v);

   // 2) reverse the vector
   cout << "\n2) Reverse the vector:\n";
   reverse(v.begin(), v.end());
   printVector(v);

   // 3) count occurrences of an element (count how many 30s)
   cout << "\n3) Count occurrences of 30:\n";
   int cnt = count(v.begin(), v.end(), 30);
   cout << "Number of 30s: " << cnt << "\n";

   // 4) rotate vector left by 2 positions
   cout << "\n4) Rotate vector left by 2 positions:\n";
   rotate(v.begin(), v.begin() + 2, v.end());
   printVector(v);
   // rotate(first, middle, last) moves [middle, last) to the front,
   // and [first, middle) to the back.

   // 5) sort the vector
   cout << "\n5) Sort the vector:\n";
   sort(v.begin(), v.end());
   printVector(v);
   // based on INTROSORT algorithm, which is a hybrid of 3 algos: quicksort, heapsort, and insertion sort
   return 0;
}
