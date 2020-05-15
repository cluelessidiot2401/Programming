#include <bits/stdc++.h>
using namespace std;

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0, i = (1 << 31), j = 1;
        while(i != 0){
            reverse += ((n&i)? j: 0);
            i >>= 1;
            j <<= 1;
        }
        return reverse;
    }
};