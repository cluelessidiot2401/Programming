#include <bits/stdc++.h>
using namespace std;

#define deb(x)  cout << #x << " = " << x << "; ";
static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();

class Solution {

private:
    
    double solveForMedian(vector<int>& a, vector<int>& b){
        int n = a.size(), m = b.size();
        
        if(n == 0){
            int idx = m/2;
            if(m&1) return b[idx];
            else    return (double)(b[idx]+b[idx-1])/2.0;
        }
        else if(m==0){
            int idx = n/2;
            if(n&1) return a[idx];
            else    return (double)(a[idx]+a[idx-1])/2.0;
        }
        
        if(a[n-1] <= b[0]){
            if((m+n)&1){
                int idx = (m+n)/2;
                if(idx >= n) return b[idx-n];
                else    return a[idx];
            }
            else{
                int idx = (m+n)/2 - 1;
                double ans = 0;
                if(idx >= n) ans += b[idx-n];
                else    ans += a[idx];
                ++idx;
                if(idx >= n) ans += b[idx-n];
                else    ans += a[idx];
                
                return ans/2;
            }
        }
        else if(a[0] >= b[m-1]){
            if((m+n)&1){
                int idx = (m+n)/2;
                if(idx >= m) return a[idx-m];
                else    return b[idx];
            }
            else{
                int idx = (m+n)/2 - 1;
                double ans = 0;
                if(idx >= m) ans += a[idx-m];
                else    ans += b[idx];
                ++idx;
                if(idx >= m) ans += a[idx-m];
                else    ans += b[idx];
                
                return ans/2;
            }            
        }      
        
        int l = 0, h = n, i, j;
        int idx = (m+n)/2;
        bool condition;
        double ans;

        while(l <= h)
        {
            i = (l+h)/2;
            j = idx - i;

            condition = true;
            if(i > 0)   condition = condition && (a[i-1] <= b[j]);
            if(j > 0 && i<n)   condition = condition && (b[j-1] <= a[i]);

            if(condition){
                if((n+m)&1){
                    return (i<n) ? min(a[i], b[j]) : b[j];
                }
                else{
                    ans = (i>0) ? max(a[i-1], b[j-1]) : b[j-1];
                    
                    if(i<n) ans += min(a[i],b[j]);
                    else    ans += b[j];
                    
                    return ans / 2.0;
                }
            }

            if(i>0 && a[i-1] > b[j])   h = i;
            else l = i+1;
        }        
        return 0;
        
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return nums1.size() <= nums2.size() ? solveForMedian(nums1, nums2) : solveForMedian(nums2, nums1);
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    Solution solution = Solution();

    vector<int>nums1, nums2;
    assert(solution.findMedianSortedArrays(nums1 = vector<int>({1,3}), nums2 = vector<int>({2})) == 2);
    assert(solution.findMedianSortedArrays(nums1 = vector<int>({1,2}), nums2 = vector<int>({3,4})) == 2.5);
    assert(solution.findMedianSortedArrays(nums1 = vector<int>({}), nums2 = vector<int>({2})) == 2);
    assert(solution.findMedianSortedArrays(nums1 = vector<int>({4}), nums2 = vector<int>({1})) == 2.5);
}