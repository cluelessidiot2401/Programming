#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        // float  m = 0;
        // if(coordinates[1][0] != coordinates[0][0])
        //     m = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for(int i=2; i<coordinates.size(); i++) {
            if(dy*(coordinates[i][0] - coordinates[0][0]) != dx*(coordinates[i][1] - coordinates[0][1]))
                return false;
        }
        return true;
    }
};