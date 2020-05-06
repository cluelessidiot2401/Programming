// https://www.codechef.com/problems/COPS

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
    bool copHouse[101];
    int forwardCopHouse[101];
    int backwardCopHouse[101];

    while(t--)
    {
        int m,x,y,xy;
        cin>>m>>x>>y;
        xy = x*y;

        memset(copHouse, 0, sizeof(copHouse));
        f(i,m){
            int temp;
            cin>>temp;
            copHouse[temp] = true;
        }

        int _forwardCopHouse = 101 + xy;
        rfab(i, 100, 1){
            if(copHouse[i]) _forwardCopHouse = i;
            forwardCopHouse[i] = _forwardCopHouse;
        }
        int _backwardCopHouse = -xy - 1;

        int ans = 0;
        fab(i, 1, 100){
            if(copHouse[i]) _backwardCopHouse = i;
            backwardCopHouse[i] = _backwardCopHouse;

            if(i-backwardCopHouse[i] > xy && forwardCopHouse[i]-i > xy)
                ++ans;
        }
        cout<<ans<<'\n';
    }

}