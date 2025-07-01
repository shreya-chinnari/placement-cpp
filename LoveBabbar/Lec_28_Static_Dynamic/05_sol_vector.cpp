#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int n;
   cout << "Enter size of array: ";
   cin >> n;

   // ✅ Best: use std::vector (manages memory safely)
   vector<int> arr(n); // Automatically uses heap

   // Initialize
   for (int i = 0; i < n; ++i)
      arr[i] = i * 10;

   // Print
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";

   cout << endl;

   // No need to delete — vector auto-cleans up

   return 0;
}

/*
Enter size of array: 8
0 10 20 30 40 50 60 70

*/