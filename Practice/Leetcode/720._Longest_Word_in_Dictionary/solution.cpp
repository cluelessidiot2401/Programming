#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
#define SIZE 26
class Trie{
    private:
    Trie * bits[SIZE];
    bool endsHere;
    public:
    Trie(){
        endsHere = false;
        for(int i=0;i<SIZE;++i) bits[i] = nullptr;
    }
    
    void insert(string & a)
    {
        Trie *cur = this;
        for(int i = 0;i<a.size();++i){
            if(cur->bits[a[i]-'a'] == nullptr) cur->bits[a[i]-'a'] = new Trie();
            cur = cur->bits[a[i]-'a'];
        }
        cur -> endsHere = true;
    }
    
    bool possible(string & a)
    {
        bool p = true;
        Trie * cur = this;
        for(int i = 0;i<a.size();++i)
        {
            cur = cur->bits[a[i]-'a'];
            if(!cur->endsHere)  return false;
        }
        return true;
    }
    
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans="";
        Trie * head = new Trie();
        for(string word : words){
            head->insert(word);
        }
        for(string word : words){
            if((ans.size() < word.size() || (ans.size() == word.size() && ans > word)) && head->possible(word))    ans = word;
        }
        return ans;
    }
};