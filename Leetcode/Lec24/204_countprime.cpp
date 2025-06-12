class Solution
{
public:
   bool isPrime(int n)
   {
      if (n <= 1)
         return false;

      for (int i = 2; i < n; i++)
      {
         if (n % i == 0)
            return false;
      }
      return true;
   }
   int countPrimes(int n)
   {
      int count = 0;

      for (int i = 2; i < n; i++)
      {
         if (isPrime(i))
         {
            count++;
         }
      }
      return count;
   }
};

// O(n^2) complexity
// 10^12 complexity
// aaj kal ki machine 10^8 ki computation hi support karti hai so Time Limit Exceed hoga