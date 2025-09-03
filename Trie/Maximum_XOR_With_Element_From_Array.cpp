#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution {
    struct Trie {
        Trie* child[2] = {nullptr, nullptr};
    };

    Trie* root = new Trie();

    void insert(int num) {
        Trie* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new Trie();
            node = node->child[bit];
        }
    }

    int getMax(int num) {
        Trie* node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {
                res |= (1 << i);
                node = node->child[1 - bit];
            } else if (node->child[bit]) {
                node = node->child[bit];
            } else {
                return -1;
            }
        }
        return res;
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<int> ans(queries.size());
        vector<tuple<int,int,int>> q;
        for (int i = 0; i < queries.size(); i++) 
            q.push_back({queries[i][1], queries[i][0], i}); // {mi, xi, idx}
        sort(q.begin(), q.end());

        int j = 0;
        for (auto [mi, xi, idx] : q) {
            while (j < nums.size() && nums[j] <= mi) insert(nums[j++]);
            ans[idx] = (j == 0 ? -1 : getMax(xi));
        }
        return ans;
    }
};
