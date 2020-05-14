#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
#define SIZE 26
class Trie {
    unordered_map<char,Trie*> bits;
    bool endsHere;
public:
    /** Initialize your data structure here. */
    Trie() {
        endsHere = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Trie* cur = this;
        for(int i = 0; i < word.size() ; ++i){
            if(cur->bits.find(word[i]) == cur->bits.end())   cur->bits[word[i]] = new Trie();
            cur = cur->bits[word[i]];
        }
        cur->endsHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        if(word == "")  return true;
        
        Trie* cur = this;
        for(int i = 0; i < word.size() ; ++i){
            if(cur->bits.find(word[i]) == cur->bits.end())   return false;
            cur = cur->bits[word[i]];
        }
        return cur->endsHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Trie* cur = this;
        for(int i = 0; i < prefix.size() ; ++i){
            if(cur->bits.find(prefix[i]) == cur->bits.end())   return false;
            cur = cur->bits[prefix[i]];
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