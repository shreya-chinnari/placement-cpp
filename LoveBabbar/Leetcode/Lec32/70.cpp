// dp

// recursove approach
class Solution
{
public:
   int climbStairs(int n)
   {
      if (n < 0)
         return 0;
      if (n == 0)
         return 1;
      return climbStairs(n - 1) + climbStairs(n - 2);
   }
};