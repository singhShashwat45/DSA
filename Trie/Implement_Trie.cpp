    struct Node{
    Node* children[26];
    bool isEnd = false;
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(!node->children[idx]) node->children[idx] = new Node();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto ch : word){
            int idx = ch - 'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto ch : prefix){
            int idx = ch - 'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */