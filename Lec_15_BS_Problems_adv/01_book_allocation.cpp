/*
Given an array arr of integer numbers, where arr[i] represents the number of pages in the i-th book. There are n number of students and the task is to allocate all the books to these students.

Allocate books in such a way that:

   1 - Each student gets at least one book.
   2 - Each book should be allocated to a student.
   3 - Book allocation should be in a contiguous manner.

You have to allocate the books to m students such that the maximum number of pages assigned to a student is minimized.

Let’s consider:

   n = 4 (number of books)
   m = 2 (number of students)
   arr = {10, 20, 30, 40}
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> &arr, int no_of_books, int no_of_students, int mid)
{
   int student_count = 1; // start with one student
   int pages_sum = 0;     // sum of pages allocated to the current student

   for (int book_index = 0; book_index <= no_of_books; book_index++)
   {
      if (pages_sum + arr[book_index] <= mid)
      {
         pages_sum = pages_sum + arr[book_index]; // allocate book to current student
      }
      else
      {
         student_count++; // move to next student

         if (student_count > no_of_students || arr[book_index] > mid)
         {
            return false; // too many students or book too large for any student
         }
         pages_sum = arr[book_index]; // allocate book to new student
      }
   }
   return true; // all books allocated successfully
}

int allocateBooks(vector<int> &arr, int no_of_books, int no_of_students)
{
   int start = 0;
   int sum_of_all_array_elements = 0;

   for (int book_index = 0; book_index < no_of_books; book_index++)
   {
      sum_of_all_array_elements = sum_of_all_array_elements + arr[book_index];
   }

   // allot end as the sum of all pages
   int end = sum_of_all_array_elements;
   int ans = -1; // to store the answer
   int mid = start + (end - start) / 2;

   while (start <= end)
   {
      if (isPossibleSolution(arr, no_of_books - 1, no_of_students, mid))
      {
         ans = mid;     // found a possible solution
         end = mid - 1; // try for a better (smaller) solution on the left side because we want to minimize the maximum pages
      }
      else
      {                   // if we didn't find a possible solution, we move to the right side because we need to increase the maximum pages
         start = mid + 1; // move to the right side to find a larger solution
      }
      mid = start + (end - start) / 2; // recalculate mid for new start/end values
   }
   return ans; // return the minimum "maximum pages" allocated to a student
}

int main()
{
   // Sample test case
   int n = 4; // number of books
   int m = 2; // number of students
   vector<int> arr = {10, 20, 30, 40};

   // Call the allocateBooks function
   int result = allocateBooks(arr, n, m);

   // Output the result
   cout << "Minimum of the maximum number of pages allocated to a student is: " << result << endl;

   return 0;
}