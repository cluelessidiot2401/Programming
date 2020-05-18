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
        
        int ans = a[0], maxSoFar = a[0], maxEndingHere = a[0], sum = a[0];
        
        for(int i = 1; i < n ;++i)
        {
            maxEndingHere = max(a[i], maxEndingHere + a[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
            sum += a[i];
        }
        ans = maxSoFar;

        int minSoFar = a[1], minEndingHere = a[1];
        for(int i = 2; i < n - 1 ; ++i)
        {
            minEndingHere = min(a[i], a[i] + minEndingHere);
            minSoFar = min(minSoFar, minEndingHere);
        }
        return max(ans, sum - minSoFar);
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