// https://www.spoj.com/problems/HISTOGRA/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define rfab(i,a,b) for(int i=a;i>=b;--i)
#define MAX_LEN (int)(1e5)
#define hp pair<ll, int>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

    while(1)
    {
        int n;
        cin>>n;

        if(n == 0)
            break;

        stack<hp> heights;
        ll ans = 0;
        f(i,n){
            ll height;
            cin>>height;

            ans = max(ans, height);

            if(heights.empty() || heights.top().first < height)
                heights.push({height, i});
            else
            {
                //heights.top().first >= height
                // stack (top to bottom) => [{6,2}, {5,1}]
                // height = 5
                // hp highest = heights.top();
                hp lastPopped;
                while(!heights.empty() && heights.top().first > height)
                {
                    ans = max(ans, heights.top().first * (i - heights.top().second ));
                    lastPopped = heights.top();
                    heights.pop();
                }
                if(heights.empty() || heights.top().first < height)
                    heights.push( {height, lastPopped.second} );
            }
        }
        while(!heights.empty())
        {
            ans = max(ans, heights.top().first * (n - heights.top().second ));
            heights.pop();
        }
        cout<<ans<<'\n';
    }

}