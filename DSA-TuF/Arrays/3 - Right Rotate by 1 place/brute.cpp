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

// Brute force
// Out-Of-Place rotation
// we create a new array (temp[n]) and copy the new elements in the new array
// it occupies extra space of O(n)

void rotateByOnePlace(vector<int> &v)
{
   if (v.empty())
      return;

   int n = v.size();

   vector<int> temp(n);
   for (int i = 0; i < n - 1; i++)
   {
      temp[i + 1] = v[i];
   }
   temp[0] = v[n - 1];

   v = temp;
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