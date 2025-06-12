#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   int countPrimes(int n)
   {
      int count = 0;

      // Step 1: Create a boolean vector of size n and initialize all to true
      // (Initially assuming all numbers < n are prime)
      vector<bool> prime(n, true);

      // 0 and 1 are not prime
      if (n > 0)
         prime[0] = false;
      if (n > 1)
         prime[1] = false;

      // Step 2: Sieve of Eratosthenes
      for (int i = 2; i < n; i++)
      {
         if (prime[i])
         {
            count++; // if i is still marked prime, increase count

            // Mark all multiples of i as non-prime
            for (int j = 2 * i; j < n; j += i)
            {
               prime[j] = false;
            }
         }
      }

      return count;
   }
};

// Step 3: Test it with main function
int main()
{
   Solution sol;
   int n;
   cout << "Enter the value of n: ";
   cin >> n;

   int result = sol.countPrimes(n);
   cout << "Number of prime numbers less than " << n << " is: " << result << endl;

   return 0;
}
