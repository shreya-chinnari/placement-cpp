
// ❓ Problem: Find the maximum length of a subarray with all 1s if you are allowed to flip at most k zeroes.

// TC : O(n)
// SC : O(1)

/*

---

### 🔍 Important Difference from `while`:

In the `while` loop version, we kept shrinking `l` **until** zeros ≤ k, but here we **only shrink once** per `r`, so zeros is still 3, which makes the window invalid but we **continue**.

---

### 🔁 r ends (n = 7)

---

### ⚠️ Final Issue:
Although the current subarray contains **3 zeroes (exceeds k)**, `len = r - l + 1 = 6` gets considered and `maxLen` stays `6`.
So `if (zeros > k)` doesn’t **strictly maintain the window validity**.

---

### ✅ Final Output:
```cpp
maxLen = 6


*/
#include <iostream>
using namespace std;

int maxOnes(int arr[], int n, int k)
{
   int l = 0, r = 0;
   int zeros = 0;
   int maxLen = 0, len = 0;

   while (r < n)
   {
      if (arr[r] == 0)
         zeros++;

      // while (zeros > k)
      if (zeros > k) // not allowing to extend the size
      {
         if (arr[l] == 0)
         {
            zeros--;
         }
         l++;
      }

      if (zeros <= k)
      {
         len = r - l + 1;
         maxLen = max(len, maxLen);
      }
      r++;
   }

   return maxLen;
}

int main()
{
   int arr[11] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
   int k = 2;

   cout << "max len : " << maxOnes(arr, 11, k) << endl;

   return 0;
}
