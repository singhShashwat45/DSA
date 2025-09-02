#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct Trie{
    Trie* children[26] = {NULL};
    bool isEnd = false;
};

class Solution {
    public:
    Trie* root = new Trie();
    void insert(string word){
        Trie* node = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(!node->children[idx]) node->children[idx] = new Trie();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool checkAllPrefixes(string word){
        Trie* node = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            if (!node->isEnd) return false;
        }
        return true;
    }
    
    string longestValidWord(vector<string>& words) {
        for(int i=0; i< words.size(); i++){
            insert(words[i]);
        }
        string ans = "";
        for (auto &w : words) {
            if (checkAllPrefixes(w)) {
                if (w.size() > ans.size() || (w.size() == ans.size() && w < ans)) {
                    ans = w;
                }
            }
        }
        return ans;
    }
};
