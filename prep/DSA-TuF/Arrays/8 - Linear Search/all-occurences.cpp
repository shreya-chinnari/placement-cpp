#include <iostream>
#include <vector>

using namespace std;

vector<int> findAllOccurrences(const vector<int> &arr, int x)
{
   vector<int> indices;

   // Traverse the array and collect all indices where arr[i] == x
   for (int i = 0; i < arr.size(); ++i)
   {
      if (arr[i] == x)
      {
         indices.push_back(i);
      }
   }

   return indices;
}

int main()
{
   vector<int> arr = {5, 3, 7, 3, 8, 3, 1};
   int target = 3;

   vector<int> result = findAllOccurrences(arr, target);

   cout << "Occurrences of " << target << " found at indices: ";
   for (int idx : result)
   {
      cout << idx << " ";
   }
   cout << endl;

   return 0;
}
