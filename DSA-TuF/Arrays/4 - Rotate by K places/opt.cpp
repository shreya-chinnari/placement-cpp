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

void rotateByKPlaceLeft(vector<int> &v)
{
}

void rotateByKPlaceRight(vector<int> &v)
{
}

int main()
{

   cout << "Left Rotate by 1 place:\n";
   vector<int> v1 = {1, 2, 3, 4, 5};
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   cout << "Right Rotate by 1 place:\n";
   vector<int> v2 = {1, 2, 3, 4, 5};
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   return 0;
}