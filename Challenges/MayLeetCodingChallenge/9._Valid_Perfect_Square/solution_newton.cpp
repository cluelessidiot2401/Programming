#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0)    return false;
        if(num == 1)    return true;
        
        int sqrt_num = min(num, 46341); // can assign any initial value to this variable
        int approximation;
        int minDiff = num;
        while(1)
        {
            approximation = (sqrt_num + num/ sqrt_num)/2;

            int diff = abs(approximation - sqrt_num);
            if(minDiff <= diff || minDiff == 0) return sqrt_num*sqrt_num == num;
            else    minDiff = diff;
            
            sqrt_num = approximation;
        }
        return sqrt_num*sqrt_num == num;
    }
};