#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    int maxProduct(vector<int>& a) {
        
        int ans = a[0], maxEndingHere = a[0], minEndingHere = a[0];
        // int tmp;
        for(int i = 1; i < a.size(); ++i){
            std::tie(minEndingHere, maxEndingHere) = std::minmax({a[i], a[i]*maxEndingHere, a[i]*minEndingHere});
            // tmp = maxEndingHere;
            // maxEndingHere = max(max(a[i], a[i]*maxEndingHere), a[i]*minEndingHere);
            // minEndingHere = min(min(a[i], a[i]*minEndingHere), a[i]*tmp);
            ans = max(ans, maxEndingHere);
        }
        return ans;
    }
};