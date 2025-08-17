#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
   list<int> l; // using list instead of stack to simulate

   for (int i = 0; i < asteroids.size(); i++)
   {
      int a = asteroids[i];

      if (a > 0)
      {
         // moving right → safe, push
         l.push_back(a);
      }
      else
      {
         // while top exists, moves right, & is positive & smaller → pop it
         while (!l.empty() && l.back() > 0 && l.back() < abs(a))
         {
            l.pop_back();
         }

         // case: same size → destroy both
         if (!l.empty() && l.back() == abs(a))
         {
            l.pop_back();
         }
         // case: survived (no right-moving asteroid or only negatives left)
         else if (l.empty() || l.back() < 0)
         {
            l.push_back(a);
         }
      }
   }

   // convert list back to vector
   return vector<int>(l.begin(), l.end());
}

int main()
{
   vector<int> arr = {
       4,
       7,
       1,
       1,
       2,
       -3,
       -7,
       17,
       15,
       -16};
   vector<int> res = asteroidCollision(arr);

   for (int x : res)
      cout << x << " ";
   cout << endl;

   vector<int> arr2 = {
       4,
       7,
       1,
       1,
       2,
       -3,
       -7,
       17,
       15,
       -18, -19};
   vector<int> res1 = asteroidCollision(arr2);

   for (int x : res1)
      cout << x << " ";
   // Expected: [ -18, -19 ]
   return 0;
}
