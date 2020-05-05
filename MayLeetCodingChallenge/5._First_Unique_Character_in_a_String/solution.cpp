#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int vis[26];
        memset(vis, -1, sizeof(vis));
        
        for(int i=0;i<s.size();++i) {
            if(vis[s[i]-'a'] == -1)   vis[s[i]-'a'] = i;
            else    vis[s[i]-'a'] = -2;
        }
        for(int i=0;i<s.size();++i){
            if(vis[s[i]-'a']>=0)
                return vis[s[i]-'a'];
        }
        return -1;
    }
};