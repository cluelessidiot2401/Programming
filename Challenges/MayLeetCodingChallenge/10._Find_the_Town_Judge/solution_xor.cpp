#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();

class Solution {
    int trustCount[1001];
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        memset(trustCount, 0, sizeof(int)*(N+1));
        int judge = 0;
        for(int i = 0; i < trust.size(); ++i)
        {
            ++trustCount[trust[i][1]];
            --trustCount[trust[i][0]];
            if(trustCount[trust[i][1]] == N-1)  judge ^= trust[i][1];
            if(trustCount[trust[i][0]] == N-2)  judge ^= trust[i][0];
        }
        if(judge == 0)  judge = -1;
        if(N == 1)  judge = 1;
        return judge;
    }
};