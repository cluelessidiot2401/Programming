#include <bits/stdc++.h>
using namespace std;

#define slopeXY pair<int,int>
class Solution {
    private:
        void reduceSlope(slopeXY& slope){
            if(slope.first == 0 || slope.second == 0)   return;
            int gcdXY = __gcd(abs(slope.first), abs(slope.second));
            if(slope.second < 0)    slope = {-slope.first/gcdXY, -slope.second/gcdXY};
            else    slope = {slope.first/gcdXY, slope.second/gcdXY};
        }
    
        bool areSlopesEqual(slopeXY& slope1, slopeXY& slope2){
            if((slope1.first == 0 && slope2.first == 0) || (slope1.second == 0 && slope2.second == 0))
                return true;
            reduceSlope(slope2);
            return slope1.first == slope2.first && slope1.second == slope2.second;
        }
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        slopeXY slope = {coordinates[1][0] - coordinates[0][0],
                          coordinates[1][1] - coordinates[0][1]};
        reduceSlope(slope);        
        
        for(int i=2;i<coordinates.size();++i){
            slopeXY cur = {coordinates[i][0] - coordinates[0][0],
                          coordinates[i][1] - coordinates[0][1]};
            if(!areSlopesEqual(slope, cur)) return false;
        }
        return true;
    }
};