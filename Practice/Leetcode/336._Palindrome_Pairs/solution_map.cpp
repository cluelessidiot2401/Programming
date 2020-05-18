#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();

class Solution {
    
    bool isPalindrome(string &a, int st, int end){
        while(st < end){
            if(a[st] != a[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    
    bool isPalindrome(string &a){
        return isPalindrome(a, 0, a.size()-1);
    }
    
    bool isPalindrome(string &a, string &b){
        if(a == "") return isPalindrome(b);
        if(b == "") return isPalindrome(a);
        
        int n = a.size(), m = b.size();
        int i = 0, j = m-1;
        while(i<n && j>=0){
            if(a[i] != b[j])    return false;
            ++i;
            --j;
        }
        if(i>=n) return isPalindrome(b, 0, j);
        if(j<0) return isPalindrome(a, i, n-1);
        
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> ans;
        vector<int> cur(2);
        unordered_map<string, int> um;
        unordered_map<string, int> :: iterator it;
        f(i,n)  um[words[i]] = i;
        
        f(i,n)
        {
            string word = words[i];
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            
            if((it = um.find(rev)) != um.end()){
                if(it->second != i){
                    cur[0] = i; 
                    cur[1] = it->second;
                    ans.push_back(cur);
                }
            }
            int len = rev.size();
            for(int k = 1; k <= len; ++k)
            {
                if(isPalindrome(rev, 0, k-1)){
                    it = um.find(rev.substr(k));
                    if(it != um.end() && it->second != i){
                        cur[0] = i, cur[1] = it->second;
                        ans.push_back(cur);
                    }
                }
                
                if(isPalindrome(word, 0, k-1)){
                    it = um.find(rev.substr(0, len-k));
                    if(it != um.end() && it->second != i){
                        cur[0] = it->second, cur[1] = i;
                        ans.push_back(cur);
                    }
                }
            }
        }
        return ans;
    }
};