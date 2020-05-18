#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num == 0)    return false;
        if(num == 1)    return true;
        
        unsigned int l = 1, h = 46341, mid, midSq;
        while(l < h)
        {
            mid = l/2 + h/2;
            midSq = mid*mid;
            if(midSq < num)   l = mid+1;
            else if(midSq > num)    h = mid-1;
            else    return mid;
        }
        return l * l == num;
    }
};