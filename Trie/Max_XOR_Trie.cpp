#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct Trie{
    Trie* links[2];
    Trie(){
        for(int i=0; i<2;i++){
            links[i] = NULL;
        }
    }
};

class Solution {
public:
    Trie* root = new Trie();
    void insert(int num){
        Trie* node = root;
        for(int i=31; i>=0; i--){
            int bit = num>>i & 1;
            if(!node->links[bit]) node->links[bit] = new Trie();
            node=node->links[bit];
        }
    }
    int getMax(int num){
        Trie* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = num>>i & 1;
            if(node->links[1-bit]) {
                maxNum = maxNum | 1<<i;
                node =  node->links[1-bit];
            }
            else
            node=node->links[bit];
        }
        return maxNum;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(auto &it : nums){
            insert(it);
        }
        int maxi= 0;
        for(auto &it: nums){
            getMax(it);
            maxi = max(maxi, getMax(it));
        }
        return maxi;
    }
};
