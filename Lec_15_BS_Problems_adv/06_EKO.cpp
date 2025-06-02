/*
Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.
*/

/*
✅ Problem Summary:

You are given:

   - N trees with heights.
   - You need to collect at least M meters of wood.

You can set the machine to a height H. The machine will cut only the parts above H from each tree. Your goal is to find the maximum possible H such that the total wood collected is at least M.


🧠 Approach: Binary Search
We are maximizing the value of H such that collected wood ≥ M.

Steps:
   - Search space: low = 0 to high = max height of tree
   - Mid = (low + high) / 2
   - For each mid, check if you can collect at least M wood.
      - If yes, try a higher mid to maximize H.
      - If no, reduce mid.

This is a classic binary search on answer.

*/
#include <iostream>  // For input/output
#include <vector>    // For vector container
#include <algorithm> // For max_element
using namespace std;

// Function to check if we can collect at least M wood with saw height 'mid'
bool isEnoughWood(const vector<int> &trees, int M, int mid)
{
   long long totalWood = 0; // Use long long to avoid overflow

   // trees is a vector that contains the heights of the trees.
   // height is a copy of the current tree’s height in each iteration.
   for (int height : trees)
   {
      if (height > mid)
      {
         totalWood += (height - mid);
      }
   }
   // Loop over all trees
   // If tree is taller than mid, collect the upper part (cut height = height - mid)
   // Add this to totalWood
   return totalWood >= M;

   // true if enough wood collected(i.e., total ≥ required)
   // false otherwise
}

// Main function to find maximum possible height H
int findSawHeight(vector<int> &trees, int M)
{
   int low = 0;
   int high = *max_element(trees.begin(), trees.end()); // Max height among trees
   int result = 0;                                      // Stores the final answer

   while (low <= high)
   {
      int mid = (low + high) / 2;

      if (isEnoughWood(trees, M, mid))
      {
         result = mid; // mid is a valid height, try higher
         low = mid + 1;
      }
      else
      {
         high = mid - 1; // not enough wood, try lower
      }
   }
   return result;
}

int main()
{
   int N, M;
   cout << "Enter number of trees (N) and required wood (M): ";
   cin >> N >> M;

   vector<int> trees(N);
   cout << "Enter the heights of the " << N << " trees: ";
   for (int i = 0; i < N; i++)
   {
      cin >> trees[i];
   }

   int maxHeight = findSawHeight(trees, M);
   cout << "Maximum height to set the sawblade: " << maxHeight << " meters" << endl;

   return 0;
}
