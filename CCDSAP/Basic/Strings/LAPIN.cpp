// https://www.codechef.com/problems/LAPIN

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
        cin>> s;
        int n = s.size();

        int frequency[256][2];
        memset(frequency,0,sizeof(frequency));

        int i = 0, j = n-1;

        while(i<j)
        {
            ++frequency[(int)s[i++]][0];
            ++frequency[(int)s[j--]][1];
        }
        bool isLapindrome = true;
        f(i,256)
            if(frequency[i][0] != frequency[i][1])
            {
                isLapindrome = false;
                break;
            }
        
        cout<<(isLapindrome ? "YES\n" : "NO\n");




    }

}