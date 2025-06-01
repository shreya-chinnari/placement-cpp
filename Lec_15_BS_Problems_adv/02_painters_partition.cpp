// Painter's Partition Problem

/*
You are given an array of integers representing the lengths of boards. You need to paint these boards using 'k' painters, where each painter can paint one board at a time and takes unit time to paint unit board. The goal is to minimize the maximum time taken by any painter.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> &arr, int no_of_boards, int no_of_painters, int mid)
{
   int painter_count = 1; // start with one painter
   int boards_sum = 0;    // sum of boards allocated to the current painter

   for (int board_index = 0; board_index <= no_of_boards; board_index++)
   {
      if (boards_sum + arr[board_index] <= mid)
      {
         boards_sum += arr[board_index]; // allocate board to current painter
      }
      else
      {
         painter_count++; // start a new painter
         if (painter_count > no_of_painters || arr[board_index] > mid)
         {
            return false; // too many painters or board too large for any painter
         }
         boards_sum = arr[board_index]; // allocate board to new painter
      }
   }
   return true; // all boards allocated successfully
}

int allocateBoards(vector<int> &arr, int no_of_boards, int no_of_painters)
{
   int start = 0;
   int sum_of_all_array_elements = 0;

   for (int board_index = 0; board_index < no_of_boards; board_index++)
   {
      sum_of_all_array_elements += arr[board_index];
   }

   // allot end as the sum of all boards
   int end = sum_of_all_array_elements;
   int ans = -1; // to store the answer
   int mid = start + (end - start) / 2;

   while (start <= end)
   {
      if (isPossibleSolution(arr, no_of_boards - 1, no_of_painters, mid))
      {
         ans = mid;     // found a possible solution
         end = mid - 1; // try for a better (smaller) solution on the left side because we want to minimize the maximum time
      }
      else
      {                   // if we didn't find a possible solution, we move to the right side because we need to increase the maximum time
         start = mid + 1; // move to the right side to find a larger solution
      }
      mid = start + (end - start) / 2; // recalculate mid for new start/end values
   }
   return ans; // return the minimum "maximum time" allocated to a painter
}
int main()
{
   // Sample test case
   int n = 4; // number of books
   int m = 2; // number of students
   vector<int> arr = {10, 20, 30, 40};

   // Call the allocateBooks function
   int result = allocateBoards(arr, n, m);

   // Output the result
   cout << "Minimum of the maximum number of boards allocated to a painter is: " << result << endl;

   return 0;
}