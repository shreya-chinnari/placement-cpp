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

void rotateByOnePlaceLeft(vector<int> &v)
{
   int n = v.size();

   int temp = v[0];

   for (int i = 0; i < n - 1; i++)
   {
      v[i] = v[i + 1]; // Shift elements to the left
   }
   v[n - 1] = temp; // Place the first element at the end
}

void rotateByOnePlaceRight(vector<int> &v)
{
   int n = v.size();
   if (n == 0)
      return;

   int temp = v[n - 1]; // Store the last element

   // Shift elements to the right from the end
   for (int i = n - 1; i > 0; i--)
   {
      v[i] = v[i - 1]; // Shift elements to the right
   }
   v[0] = temp; // Place the first element at the end
}
int main()
{

   cout << "Left Rotate by 1 place:\n";
   vector<int> v = {1, 2, 3, 4, 5};
   printArray(v);
   rotateByOnePlaceLeft(v);
   printArray(v);
   rotateByOnePlaceLeft(v);
   printArray(v);
   rotateByOnePlaceLeft(v);
   printArray(v);
   rotateByOnePlaceLeft(v);
   printArray(v);
   cout << "Right Rotate by 1 place:\n";
   v = {1, 2, 3, 4, 5};
   printArray(v);
   rotateByOnePlaceRight(v);
   printArray(v);
   rotateByOnePlaceRight(v);
   printArray(v);
   rotateByOnePlaceRight(v);
   printArray(v);
   rotateByOnePlaceRight(v);
   printArray(v);
   return 0;
}