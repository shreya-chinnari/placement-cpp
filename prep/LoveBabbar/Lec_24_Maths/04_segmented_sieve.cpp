// The Segmented Sieve is an advanced version of the Sieve of Eratosthenes, used when you need to find all prime numbers in a given range [L, R], especially when R is large (e.g. up to 10^12)

/*
✅ Why Segmented Sieve?

   The regular sieve creates a bool[] of size R, which is memory-inefficient if R is huge.

   The segmented sieve breaks the range into smaller chunks and reuses memory efficiently.

   It uses the primes up to sqrt(R) - (found using normal sieve) - to mark non-primes in the segment [L, R].
*/

/*
📊 Example:

Find all primes between L = 10 and R = 20.

First, find primes up to
sqrt(𝑅)=sqrt(20)≈4.47
→ Use simple sieve to get: [2, 3]
Then mark multiples of these primes in range [10, 20].
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ✅ Standard sieve to get all prime numbers up to sqrt(R)
vector<int> simpleSieve(int limit)
{
   // Create a boolean array of size limit + 1, initially marking all numbers as prime (true)
   vector<bool> isPrime(limit + 1, true);
   isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

   // Use Sieve of Eratosthenes
   for (int i = 2; i * i <= limit; i++)
   {
      if (isPrime[i])
      {
         // Mark all multiples of i as non-prime
         for (int j = i * i; j <= limit; j += i)
            isPrime[j] = false;
      }
   }

   // Collect all prime numbers up to limit
   vector<int> primes;
   for (int i = 2; i <= limit; i++)
      if (isPrime[i])
         primes.push_back(i);

   return primes;
}

// ✅ Segmented Sieve for range [L, R]
vector<int> segmentedSieve(int L, int R)
{
   int limit = sqrt(R) + 1;                 // We need primes up to sqrt(R)
   vector<int> primes = simpleSieve(limit); // Get small primes using normal sieve

   int size = R - L + 1;             // Size of the range
   vector<bool> isPrime(size, true); // Initially assume all in [L, R] are prime

   // Mark non-primes in [L, R] using small primes
   for (int prime : primes)
   {
      // Find the first multiple of 'prime' in the range [L, R]
      int start = max(prime * prime, (L + prime - 1) / prime * prime);

      // Mark all multiples of 'prime' in the range as not prime
      for (int j = start; j <= R; j += prime)
         isPrime[j - L] = false; // j - L is the index in isPrime[] , We're not storing numbers directly from 0 to R, but from L to R. So we need to shift the index when marking.

      /*
      Example:

      -   If L = 10 and j = 12, then j - L = 2.
      -   So, isPrime[2] = false → means 12 is not a prime.
      */
   }

   // Collect the remaining prime numbers in [L, R]
   vector<int> result;
   for (int i = 0; i < size; i++)
   {
      if (isPrime[i] && (i + L) >= 2)
         result.push_back(i + L);
   }

   return result; // Return the list of primes
}

// ✅ Main function to test the segmented sieve
int main()
{
   int L, R;
   cout << "Enter range L and R: ";
   cin >> L >> R;

   // Call segmented sieve function
   vector<int> primes = segmentedSieve(L, R);

   // Print the prime numbers
   cout << "Primes between " << L << " and " << R << ":\n";
   for (int p : primes)
      cout << p << " ";
   cout << endl;

   return 0;
}

/*
🧠 Summary of Key Steps:
   > : Generate small primes up to √R using the regular sieve (simpleSieve).
   > : Assume all numbers in [L, R] are prime, then eliminate multiples of small primes.
   > : Finally, collect unmarked (prime) numbers and print them.
*/