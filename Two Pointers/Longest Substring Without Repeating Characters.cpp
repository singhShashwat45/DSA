#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int n = s.size();
        int left = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
