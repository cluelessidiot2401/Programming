// https://www.codechef.com/problems/SALARY

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;
typedef long long ll;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define rfab(i,a,b) for(int i=a;i>=b;--i)
#define MAX_LEN (int)(1e6)

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	int t;
    cin>>t;

    int a[101];
    while(t--)
    {
        int n;
        cin>>n;

        f(i,n)  cin>>a[i];
        sort(a,a+n);

        long ans = 0;
        int add = 0;
        int diff = 0;
        fab(i,1,n-1)
        {
            a[i] += add;
            diff = (a[i] - a[i-1]);
            ans += diff;
            add += diff;
        }
        cout<<ans<<'\n';

    }

}