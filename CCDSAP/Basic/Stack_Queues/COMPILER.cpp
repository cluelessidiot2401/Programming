// https://www.codechef.com/problems/COMPILER

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
        string s;
        cin>>s;

        int n = s.size();
        int ans = 0;
        int current = 0;

        f(i,n){
            if(s[i] == '<') ++current;
            else {
                --current;
                if(current<0)   break;
            }
            if(current == 0 )
            ans = i+1;
        }
        cout << ans<<'\n';

    }

}