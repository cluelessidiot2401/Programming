#include <bits/stdc++.h>
using namespace std;

// static vector<int> trustCount=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return vector<int>(1001,0);
// }();
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if(n == 1)  return a[0];

        int l = 0, h = n - 1, left;
        
        while(l<h){
            int mid = (l+h)/2;
            
            if(((mid>0 && a[mid-1] != a[mid]) || mid == 0) && ((mid<n-1 && a[mid+1] != a[mid]) || mid == n-1))
                return a[mid];
            
            left = mid - l + 1;

            if(a[l+1] != a[l])  return a[l];
            
            if(mid&1){
                if(a[mid] == a[mid+1])  h = mid-1;
                else    l = mid+1;
            }
            else if (a[mid] != a[mid+1])    h = mid - 2;
            else    l = mid + 2;
        }
        return a[l];
    }
};