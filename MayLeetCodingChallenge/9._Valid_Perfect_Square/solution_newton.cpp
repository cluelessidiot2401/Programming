#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0)    return false;
        if(num == 1)    return true;
        
        int sqrt = min(num, 46341); // can assign any initial value to this variable
        int approximation;
        int minDiff = num;
        while(1)
        {
            approximation = (sqrt + num/sqrt)/2;
            int diff = abs(approximation - sqrt);
            if(minDiff <= diff)
                break;
            else    minDiff = diff;
            if(minDiff == 0)    return sqrt*sqrt == num;
            sqrt = approximation;
        }
        return sqrt*sqrt == num;
    }
};