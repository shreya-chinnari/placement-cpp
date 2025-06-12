#include <iostream>
#include <vector>
using namespace std;

// Function to count and return all prime numbers less than n
vector<int> countAndListPrimes(int n)
{
   vector<bool> isPrime(n, true); // Assume all numbers are prime initially
   if (n > 0)
      isPrime[0] = false;
   if (n > 1)
      isPrime[1] = false;

   // Sieve of Eratosthenes Algorithm
   for (int i = 2; i * i < n; i++)
   {
      if (isPrime[i])
      {
         // Mark all multiples of i as non-prime
         for (int j = i * i; j < n; j += i)
         {
            isPrime[j] = false;
         }
      }
   }

   // Collect all prime numbers
   vector<int> primes;
   for (int i = 2; i < n; i++)
   {
      if (isPrime[i])
      {
         primes.push_back(i);
      }
   }

   return primes;
}

// Main function to test the logic
int main()
{
   int n;
   cout << "Enter the value of n: ";
   cin >> n;

   // Call the function to get all primes less than n
   vector<int> primes = countAndListPrimes(n);

   // Print the result
   cout << "Number of primes less than " << n << " is: " << primes.size() << endl;
   cout << "The prime numbers are: ";
   for (int prime : primes)
   {
      cout << prime << " ";
   }
   cout << endl;

   return 0;
}
