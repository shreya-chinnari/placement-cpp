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

void rotateByOnePlaceLeft(vector<int> &v)
{
   if (v.empty())
      return;

   int n = v.size();

   vector<int> temp(n);
   for (int i = 1; i < n; i++)
   {
      temp[i - 1] = v[i];
   }
   temp[n - 1] = v[0];

   v = temp;
}

void rotateByOnePlaceRight(vector<int> &v)
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

   cout << "Left Rotate by 1 place:\n";
   vector<int> v1 = {1, 2, 3, 4, 5};
   printArray(v1);
   rotateByOnePlaceLeft(v1);
   printArray(v1);
   rotateByOnePlaceLeft(v1);
   printArray(v1);
   rotateByOnePlaceLeft(v1);
   printArray(v1);
   rotateByOnePlaceLeft(v1);
   printArray(v1);
   cout << "Right Rotate by 1 place:\n";
   vector<int> v2 = {1, 2, 3, 4, 5};
   printArray(v2);
   rotateByOnePlaceRight(v2);
   printArray(v2);
   rotateByOnePlaceRight(v2);
   printArray(v2);
   rotateByOnePlaceRight(v2);
   printArray(v2);
   rotateByOnePlaceRight(v2);
   printArray(v2);
   return 0;
}