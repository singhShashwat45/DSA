#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char t : tasks) mp[t]++;

        // max-heap by frequency
        priority_queue<int> pq;
        for (auto &it : mp) pq.push(it.second);

        int ans = 0;
        while (!pq.empty()) {
            int cycle = n + 1;  // each round
            vector<int> temp;   // store unfinished tasks

            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top(); pq.pop();
                if (--freq > 0) temp.push_back(freq);
                ans++;
                cycle--;
            }

            for (int f : temp) pq.push(f);

            if (!pq.empty()) ans += cycle; 
            // if tasks left, we must fill idle slots
        }
        return ans;
    }
};
