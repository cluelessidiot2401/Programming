#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
#define SIZE 26
class Trie {
    Trie* bits[SIZE];
    bool endsHere;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < SIZE; ++i)   bits[i] = nullptr;
        endsHere = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Trie* cur = this;
        for(int i = 0; i < word.size() ; ++i){
            if(cur->bits[word[i]-'a'] == nullptr)   cur->bits[word[i]-'a'] = new Trie();
            cur = cur->bits[word[i]-'a'];
        }
        cur->endsHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        if(word == "")  return true;
        
        Trie* cur = this;
        for(int i = 0; i < word.size() ; ++i){
            if(cur->bits[word[i]-'a'] == nullptr)   return false;
            cur = cur->bits[word[i]-'a'];
        }
        return cur->endsHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Trie* cur = this;
        for(int i = 0; i < prefix.size() ; ++i){
            if(cur->bits[prefix[i]-'a'] == nullptr)   return false;
            cur = cur->bits[prefix[i]-'a'];
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