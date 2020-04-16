// https://www.spoj.com/problems/JNEXT/
/*
7
5
1 5 4 8 3
10
1 4 7 4 5 8 4 1 2 6
10
1 4 7 4 5 8 4 3 2 1
2
1 1
5
1 6 8 9 7
8
1 4 6 7 9 8 6 5
9
1 4 6 7 9 8 7 6 5
*/
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
int a[MAX_LEN];

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

        f(i,n)  cin>>a[i];

        int i = n-1;
        while(i>0 && a[i]<=a[i-1])  --i;

        if(i>0 && a[i]>a[i-1]){

            int j = i;
            while(j<n && a[i-1]<a[j])
                ++j;
            swap(a[i-1], a[j-1]);
        }
        else{
            cout<<-1<<'\n';
            continue;
        }
        sort(a+i,a+n);
        f(i,n)  cout<<a[i];
        cout<<'\n';
    }

}