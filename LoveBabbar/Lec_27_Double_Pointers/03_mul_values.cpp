#include <iostream>
using namespace std;
void calc(int a, int b, int *sum, int *diff)
{
   *sum = a + b;
   *diff = a - b;
}

int main()
{
   int s, d;
   calc(10, 4, &s, &d);
   cout << "Sum: " << s << ", Diff: " << d << endl;
   // Output: Sum: 14, Diff: 6
}
// This code demonstrates how to use pointers to return multiple values from a function.
// The function `calc` takes two integers and two pointers, calculates their sum and difference