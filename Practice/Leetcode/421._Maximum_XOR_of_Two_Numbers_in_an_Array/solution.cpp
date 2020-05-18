#include <bits/stdc++.h>
using namespace std;

class Trie{
    
private:
    Trie* bits[2];
    
public:
    
    Trie(){
        bits[0] = nullptr;
        bits[1] = nullptr;
    }
    
    void insert(int a)
    {
        int cnt = 32, next;
        Trie * cur = this;
        for(unsigned int i = (1<<30); i != 0 ; i >>= 1)
        {
            next = ((i&a)>0 ? 1 : 0);
            if(cur->bits[next] == nullptr)   cur->bits[next] = new Trie();
            cur = cur->bits[next];
        }
    }
    
    int getXor(int a)
    {
        int cnt = 32, next, ans = 0;
        Trie * cur = this;
        
        for(unsigned int i = (1<<30); i != 0 ; i >>= 1)
        {
            next = ((i&a) ? 0 : 1);
            
            if(cur->bits[next] == nullptr){
                next = (next+1)%2;
                if(cur->bits[next] == nullptr)
                    return -1;
            }
            
            cur = cur->bits[next];
            ans += (i*next);
        }
        return ans;        
    }
    
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie * head = new Trie();
        int ans = 0, xorPair;
        for(int a : nums){
            
            xorPair = head->getXor(a);
            if(xorPair != -1)
                ans = max(ans, a^xorPair);
            
            head->insert(a);
        }
        return ans;
    }
};