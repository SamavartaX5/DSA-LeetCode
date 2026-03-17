/*
Problem: https://leetcode.com/problems/count-commas-in-range-ii/
Difficulty: Medium

Intuition:
Numbers with fewer than 4 digits have no commas. From 1000 onward, commas appear
after every three digits. So instead of checking each number individually, we can
count how many numbers fall into ranges where they contribute a fixed number of commas.

For example:
- From 1e3 to 1e6 - 1 → each number has 1 comma
- From 1e6 to 1e9 - 1 → each number has 2 commas
- From 1e9 to 1e12 - 1 → each number has 3 commas
and so on.

Approach:
We divide the range [1, n] into intervals based on powers of 1000.
For each interval, we compute how many numbers fall in it and multiply by
the number of commas contributed by each number in that interval.

Time Complexity:
O(1)
We only evaluate a constant number of conditions.

Space Complexity:
O(1)
No extra space is used.

Notes:
- Writing large numbers like 999999999 can be replaced with (1e9 - 1)
  for better readability.
- In C++, 1e9 is treated as a double. For safety, you can use long long
  constants like 1000000000LL if precision is critical.
*/

class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        else if(n >= 1e3 && n <= 999999) return n - 1000 + 1;
        else if(n >= 1e6 && n <= 999999999) return 2 * (n - 1e6 + 1) + (999999 - 1000 + 1);
        else if(n >= 1e9 && n <= 999999999999) return 3 * (n - 1e9 + 1) + 2 * (999999999 - 1e6 + 1) + (999999 - 1000 + 1);
        else if(n >= 1e12 && n <= 999999999999999) return 4 * (n - 1e12 + 1) + 3 * (999999999999 - 1e9 + 1) + 2 * (999999999 - 1e6 + 1) + (999999 - 1000 + 1);

        return 5 + 4 * (999999999999999 - 1e12 + 1) + 3 * (999999999999 - 1e9 + 1) + 2 * (999999999 - 1e6 + 1) + (999999 - 1000 + 1);
    }
};