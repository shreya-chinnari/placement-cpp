#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Helper function to calculate total hours required for a given eating speed k
int calculateHours(const vector<int> &piles, int k)
{
   int totalHours = 0;
   for (int bananas : piles)
   {
      // Ceil(bananas / k) can be done via (bananas + k - 1) / k
      totalHours += (bananas + k - 1) / k;
   }
   return totalHours;
}

// Brute-force function to find minimum k
int minEatingSpeedBruteForce(vector<int> &piles, int h)
{
   int maxBananas = 0;

   // Step 1: Find the maximum number of bananas in a pile
   for (int bananas : piles)
   {
      maxBananas = max(maxBananas, bananas);
   }

   int minK = INT_MAX;

   // Step 2: Try every possible eating speed from 1 to maxBananas
   for (int k = 1; k <= maxBananas; ++k)
   {
      int hours = calculateHours(piles, k);
      if (hours <= h)
      {
         minK = min(minK, k);
      }
   }

   return minK;
}

// Driver code
int main()
{
   vector<int> piles = {3, 6, 7, 11}; // Example input
   int h = 8;

   int result = minEatingSpeedBruteForce(piles, h);
   cout << "Minimum eating speed k: " << result << endl;

   return 0;
}
