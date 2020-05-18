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

    while(t--)
    {
        int n;
        cin>>n;

        int sum = 0, minimumWage = 1e4 + 1;
        f(i,n){
            int currentWage;
            cin>>currentWage;
            sum += currentWage;
            minimumWage = min(minimumWage, currentWage);
        }
        int ans = sum - n * minimumWage;
        cout<<ans<<'\n';
    }

}