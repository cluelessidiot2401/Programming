#include <bits/stdc++.h>
using namespace std;

// static vector<int> trustCount=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return vector<int>(1001,0);
// }();
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)   return image;
        floodFill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
        if(sr>=0 && sr < image.size() && sc>=0 && sc<image[sr].size() && image[sr][sc] == originalColor){
            image[sr][sc] = newColor;
            floodFill(image, sr-1, sc, newColor, originalColor);
            floodFill(image, sr, sc-1, newColor, originalColor);
            floodFill(image, sr, sc+1, newColor, originalColor);
            floodFill(image, sr+1, sc, newColor, originalColor);
        }
    }
};