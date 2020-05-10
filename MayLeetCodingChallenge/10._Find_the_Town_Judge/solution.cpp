#include <bits/stdc++.h>
using namespace std;

static vector<int> trustCount=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>(1001,0);
}();
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        for(int i = 0; i < trust.size(); ++i)
        {
            ++trustCount[trust[i][1]];
            --trustCount[trust[i][0]];
        }
        int ans = -1;
        for(int i = 1; i <= N; ++i){
            if(trustCount[i] == N-1)
                ans = i;
            trustCount[i] = 0;
        }
        return ans;
    }
};