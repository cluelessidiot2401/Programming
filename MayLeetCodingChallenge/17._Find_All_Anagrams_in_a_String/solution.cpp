#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define deb(x)  cout << #x << " = " << x << "; ";

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
    private:
    bool areFrequenciesEqual(vector<int>&a, vector<int>&b){
        for(int i = 0;i<26;++i){
            if(a[i] != b[i])    return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if(n < m)   return ans;

        vector<int> count(26, 0);
        vector<int> sCount(26, 0);
        
        for(char c : p) ++count[c-'a'];
        
        int i = 0, j = 0;
        while(j<n)
        {
            while(j < n && j-i+1 <= m){
                sCount[s[j]-'a']++;
                while(i <= j && sCount[s[j]-'a'] > count[s[j]-'a'] ){
                    sCount[s[i]-'a']--;
                    ++i;
                }
                if(j-i+1 == m && areFrequenciesEqual(count, sCount)){
                    ans.push_back(i);
                }
                ++j;
            }
            if(i<n)
                sCount[s[i++]-'a']--;
        }
        return ans;
    }
};