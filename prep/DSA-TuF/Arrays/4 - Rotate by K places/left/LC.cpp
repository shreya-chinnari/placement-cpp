// Reverse first n-k elements
reverse(nums.begin(), nums.begin() + (n - k));

// Reverse last k elements
reverse(nums.begin() + (n - k), nums.end());

// Reverse the entire array
reverse(nums.begin(), nums.end());