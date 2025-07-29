#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &v)
{
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
   cout << endl;
}

// Optimal approach
// In-Place rotation
// we rotate the array in-place by swapping elements
// it does not occupy extra space, O(1) space complexity
// it only creates 1 extra variable for swapping

void rotateByOnePlace(vector<int> &v)
{
   int n = v.size();

   int temp = v[0];

   for (int i = 0; i < n - 1; i++)
   {
      v[i] = v[i + 1]; // Shift elements to the left
   }
   v[n - 1] = temp; // Place the first element at the end
}

int main()
{

   vector<int> v = {1, 2, 3, 4, 5};
   printArray(v);
   rotateByOnePlace(v);
   printArray(v);
   rotateByOnePlace(v);
   printArray(v);
   rotateByOnePlace(v);
   printArray(v);
   rotateByOnePlace(v);
   printArray(v);
   return 0;
}