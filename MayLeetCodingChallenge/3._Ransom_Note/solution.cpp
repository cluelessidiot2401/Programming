#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
        
        if(ransomNote.size()>magazine.size())   return false;
        
        int um[26];
        memset(um,0,sizeof(um));
        for(int i=0;i<magazine.size();++i)
            ++um[magazine[i]-'a'];
        for(int i=0;i< ransomNote.size();++i)
        {
            if((--um[ ransomNote[i]-'a']) < 0)
                return false;
        }
        return true;
    }
};