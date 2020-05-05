#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int vis[26];
        int n = s.size();
        memset(vis, -1, sizeof(vis));
        
        for(int i=0;i<n;++i) {
            if(vis[s[i]-'a'] == -1)   vis[s[i]-'a'] = i;
            else    vis[s[i]-'a'] = -2;
        }
        int ans = n;
        for(int i=0;i<26;++i)   if(vis[i] >= 0 && ans>vis[i])  ans = vis[i];
        return (ans == n ? -1 : ans);
    }
};