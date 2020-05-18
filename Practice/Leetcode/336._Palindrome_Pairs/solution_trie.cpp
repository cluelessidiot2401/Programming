#include <bits/stdc++.h>
using namespace std;

#define deb(x)  cout << #x << " = " << x << "; ";
static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Trie{
private:
    unordered_map<char, Trie*> children;
    bool endsHere;
    int idx;
public:
    
    Trie(){
        endsHere = false;
        idx = -1;
    }
    
    bool isPalindrome(string &a)
    {
        int i = 0, j = a.size()-1;
        while(i<j){
            if(a[i] != a[j])    return false;
            ++i;
            --j;
        }
        return true;
    }
    
    bool isPalindrome(string &a, int start, int end)
    {
        int i = start, j = end;
        while(i<j){
            if(a[i] != a[j])    return false;
            ++i;
            --j;
        }
        return true;
    }
    
    void insertReverse(string& a, int index)
    {
        Trie* cur = this;
        for(int i = a.size() - 1 ; i >= 0;--i)
        {
            if(cur->children.find(a[i]) == cur->children.end())
                cur->children[a[i]] = new Trie();
            cur = cur->children[a[i]];
        }
        cur->endsHere = true;
        cur->idx = index;
    }
    
    unordered_set<int> doesPalindromeExists(string &a)
    {
        unordered_set<int> ans;
        
        Trie* cur = this;
        bool pal = true;
        for(int i = 0; i<a.size()-1;++i)
        {
            if(cur->children.find(a[i]) == cur->children.end()) {
                pal = false;
                break;
            }
            cur = cur->children[a[i]];
            if(cur->endsHere && isPalindrome(a, i+1, a.size()-1))   ans.insert(cur->idx);
        }
        if(pal)
        {
            if(cur->endsHere)   ans.insert(cur->idx);
            char last = a[a.size()-1];
            if(cur->children.find(last) == cur->children.end()) return ans;
            cur = cur->children[last];
            if(cur->endsHere)   ans.insert(cur->idx);
            traverse(cur, "", ans);
        }
        return ans;
    }
    
    void traverse(Trie *cur, string total, unordered_set<int>& ans)
    {
        if(cur->endsHere && total != "" && isPalindrome(total)) ans.insert(cur->idx);
        for(auto it: cur->children)
        {
            traverse(it.second, total+it.first, ans);
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie * head = new Trie();
        vector<vector<int>> ans;
        unordered_set<string> palindromes;        
        pair<bool, int> empty = {false, -1};
        
        for(int i = 0;i<words.size();++i ){
            head->insertReverse(words[i], i);
            if(words[i] == "")  empty = {true, i};
        }
        for(int i = 0;i<words.size();++i ){
            
            if(words[i] == ""){
                for(int j = 0; j < words.size(); ++j){
                    if(j == i)  continue;
                    if(head->isPalindrome(words[j]))
                        ans.push_back(vector<int>({i, j}));
                }
                continue;
            }
            
            unordered_set<int> cur = head->doesPalindromeExists(words[i]);
            if(empty.first && head->isPalindrome(words[i]) )
                cur.insert(empty.second);
            for(int x : cur){
                if(x == i)  continue;
                ans.push_back(vector<int>({i, x}));
            }
        }
        return ans;
    }
};