// http://codeforces.com/problemset/problem/281/D
#include <iostream>
#include <algorithm>
#include <stack>
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
    cin>>n;
    int ans = 0;
    stack<int> monotonouslyDecreasingStack;
    f(i,n){
        int current;
        cin >> current;
        while(!monotonouslyDecreasingStack.empty())
        {
            int lowestOnStack = monotonouslyDecreasingStack.top();
            ans = max(ans, lowestOnStack ^ current);
            
            if(current < lowestOnStack) break;
            monotonouslyDecreasingStack.pop();
        }
        monotonouslyDecreasingStack.push(current);
    }
    cout << ans;

}