// https://www.codechef.com/problems/RAINBOWA

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

    int a[100];
    while(t--)
    {
        int n;
        cin>>n;

        f(i,n)  cin>>a[i];
        int i=0, j= n-1;
        int num = 1;
        bool rainbow = true;
        while(i<=j)
        {
            bool encountered = false;
            while(i<=j && a[i] == a[j] && a[i] == num)  ++i, --j, encountered = true;

            if(!encountered || (encountered && num > 7)){
                rainbow = false;
                break;
            }
            num ++;
        }
        if(num != 8)    rainbow = false;
        cout<< (rainbow ? "yes\n" : "no\n");

    }

}