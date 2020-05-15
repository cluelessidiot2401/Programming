#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:

    int totalHammingDistance_1(vector<int>& nums) {
        
        int ans = 0;
        for(unsigned int i = (1<<30); i != 0; i >>= 1){
            int count[2] = {0};
            for(int a: nums)    count[(a&i) > 0 ? 1 : 0]++;
            ans += count[0]*count[1];
        }
        return ans;
        
    }

    int totalHammingDistance_2(vector<int>& nums) {
        
        int ans = 0, cnt = 31;
        bool allZero;
        while(cnt -- )
        {
            allZero = true;
            int count[2] = {0};
            for(int& a: nums){
                count[a&1]++;
                a >>= 1;
                if(a != 0)  allZero = false;
            }
            ans += count[0]*count[1];
            if(allZero) break;
        }
        return ans;
        
    }
};