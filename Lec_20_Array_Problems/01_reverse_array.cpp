#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
   cout << endl;
}

vector<int> reverseVector(vector<int> v)
{
   int start = 0, end = v.size() - 1;
   while (start <= end)
   {
      swap(v[start], v[end]);
      start++;
      end--;
   }
   return v;
}

int main()
{
   vector<int> v;
   v.push_back(23);
   v.push_back(45);
   v.push_back(67);
   v.push_back(89);
   v.push_back(12);

   cout << "Original vector: ";
   printVector(v);

   cout << "Reversed vector: ";
   vector<int> reversed = reverseVector(v); // need to assign the result to a new vector
   printVector(reversed);
   return 0;
}

/*
Original vector: 23 45 67 89 12
Reversed vector: 12 89 67 45 23
*/