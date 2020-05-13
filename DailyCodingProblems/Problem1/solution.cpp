#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define rfab(i,a,b) for(int i=a;i>=b;--i)
#define MAX_LEN (int)(1e6)

bool pairWithGivenSum(vector<int>& a, int k)
{
    unordered_set<int> encountered;
    for(int ai : a){
        if(encountered.find(k - ai) != encountered.end())   return true;
        encountered.insert(ai);
    }
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n >> k;
        vector<int> a(n);
        f(i,n)  cin>>a[i];
        cout << (pairWithGivenSum(a, k) ? "True" : "False") << '\n';
    }

}