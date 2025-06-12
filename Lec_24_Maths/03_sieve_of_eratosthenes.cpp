// The Sieve of Eratosthenes is a classical algorithm used to find all prime numbers less than a given number n efficiently.

// It is a mathematical algorithm discovered by the ancient Greek mathematician Eratosthenes. It works by repeatedly marking the multiples of each prime number starting from 2.

// If a number p is prime, then all multiples of p (like 2p, 3p, 4p, ...) are not prime.

/*
✅ Steps of the Algorithm:
   > : Create a list of booleans isPrime[] of size n and initialize all values to true.
   > : Mark 0 and 1 as false (they are not prime).
   > : Start from the first prime p = 2.
   > : For each p, mark all multiples of p (from p*p to n) as false.
   > : Repeat for next unmarked number (which is the next prime).
   > : Continue until p*p >= n.
   > : All remaining true indices in the list are prime numbers.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to count and list all prime numbers less than n
vector<int> sieveOfEratosthenes(int n)
{
   vector<bool> isPrime(n, true); // Assume all numbers < n are prime

   // 0 and 1 are not prime
   if (n > 0)
      isPrime[0] = false;
   if (n > 1)
      isPrime[1] = false;

   // Sieve algorithm
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

   // Collect all primes into a vector
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

// Main function
int main()
{
   int n;
   cout << "Enter the value of n: ";
   cin >> n;

   vector<int> primes = sieveOfEratosthenes(n);

   // Print count and list of primes
   cout << "Number of prime numbers less than " << n << " is: " << primes.size() << endl;
   cout << "Prime numbers are: ";
   for (int prime : primes)
   {
      cout << prime << " ";
   }
   cout << endl;

   return 0;
}
