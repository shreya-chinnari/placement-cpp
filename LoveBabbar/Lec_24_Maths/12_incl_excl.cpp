// Count numbers ≤ N divisible by 3 or 5

#include <iostream>
using namespace std;

int main()
{
   int N = 100;

   int div3 = N / 3;
   int div5 = N / 5;
   int div15 = N / 15;

   int result = div3 + div5 - div15; // IEP: |A ∪ B| = |A| + |B| − |A ∩ B|

   cout << "Numbers less than " << N << " divisible by 3 or 5: " << result << endl;
}
