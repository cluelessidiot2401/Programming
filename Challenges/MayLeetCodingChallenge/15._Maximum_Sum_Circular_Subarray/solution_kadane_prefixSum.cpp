#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define deb(x)  cout << #x << " = " << x << "; ";

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        
        int n = a.size();
        if(n == 1)  return a[0];

        /*
            3, 5, -3, 4, -2, 5
        ->  3  8   5  9  7   12
            12 9    4   7    3   5   <-
        =>  3  8   8  9   9   12
            12 9   7  7   5   5  <=
        */
        
        int ans = a[0], maxSoFar = a[0], maxEndingHere = a[0], prefix;
        vector<int> prefixMax(n);
        prefixMax[0] = prefix = a[0];
        
        for(int i = 1; i < n ;++i)
        {
            maxEndingHere = max(a[i], maxEndingHere + a[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
            prefix += a[i];
            prefixMax[i] = max(prefix, prefixMax[i-1]);
        }
        ans = maxSoFar;
        maxSoFar = maxEndingHere = a[n-1];
        int suffix = a[n-1], suffixMax = a[n-1];
        for(int i = n-2; i >= 0 ;--i)
        {
            if(i >= 1)
                ans = max(ans, suffixMax + prefixMax[i-1]);
            suffix += a[i];
            suffixMax = max(suffix, suffixMax);            
        }
        return ans;
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    Solution solution = Solution();

    vector<int>tests;
    assert(solution.maxSubarraySumCircular(tests = vector<int>({5, -3, 5})) == 10);
    assert(solution.maxSubarraySumCircular(tests = vector<int>({-2,4,-5,4,-5,9,4})) == 15);
    assert(solution.maxSubarraySumCircular(tests = vector<int>({3, 5, -3, 4, -2, 5})) == 15);
}