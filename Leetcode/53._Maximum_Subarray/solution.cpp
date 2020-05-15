#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans = a[0], maxEndingHere = a[0];
        for(int i = 1; i<a.size();++i)
        {
            maxEndingHere = max(a[i], maxEndingHere+a[i]);
            ans = max(ans, maxEndingHere);
        }
        return ans;
    }
};