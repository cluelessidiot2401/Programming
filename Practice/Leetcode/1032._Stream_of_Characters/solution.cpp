#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
#define SIZE 26
class Trie{
private:
    Trie* children[SIZE];
    bool endsHere;
public:
    
    Trie(){
        for(int i = 0; i < SIZE; ++i)   children[i] = nullptr;
        endsHere = false;
    }
    
    void insertReverse(string& a)
    {
        Trie* cur = this;
        for(int i = a.size()-1; i>=0; --i)
        {
            if(cur->children[a[i]-'a'] == nullptr)  cur->children[a[i]-'a'] = new Trie();
            cur = cur->children[a[i]-'a'];
        }
        cur->endsHere = true;
    }
    
    bool search(string& stream)
    {
        int i = stream.size()-1;
        Trie* cur = this;
        
        while(i>=0){
            if(cur->endsHere)   return true;
            if(cur->children[stream[i]-'a'] == nullptr) return false;
            cur = cur->children[stream[i]-'a'];
            --i;
        }
        if(cur != nullptr && cur->endsHere) return true;
        return false;
    }
};

class StreamChecker {
private:
    string stream;
    Trie * head;
public:
    StreamChecker(vector<string>& words) {
        head = new Trie();
        for(string word : words)    head->insertReverse(word);
    }
    
    bool query(char letter) {
        stream += letter;
        return head->search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */