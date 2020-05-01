// https://www.spoj.com/problems/STPAR/
/*
5
5 1 2 4 3
3
3 2 1
14
4 3 2 1 5 7 6 8 9 10 14 13 12 11
0
*/
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
#define MAX_LEN (int)(1e6)

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
    vector<int> a;
    stack<int> sideStreet;
    while(1)
    {
        int n;
        cin>>n;

        if(n==0) break;
        bool possible = true;

        int current = 1;
        f(i,n)
        {
            int temp;
            cin>>temp;
            if(!possible)
                continue;
            if(temp == current)
            {
                ++current;
                continue;
            }
            else
            {
                if(sideStreet.empty())
                    sideStreet.push(temp);
                else{
                    while (!sideStreet.empty() && current == sideStreet.top())
                    {
                        sideStreet.pop();
                        ++current;
                    }
                    if(temp == current)
                    {
                        current++;
                        continue;
                    }
                    if(sideStreet.empty() || (temp < sideStreet.top()))
                        sideStreet.push(temp);
                    else{
                        possible = false;
                        continue;
                    }
                }
            }          

        }
        while(!sideStreet.empty()){
            if(!possible){
                sideStreet.pop();
                continue;
            }
            if(sideStreet.top() == current) ++current;
            else    possible = false;
            sideStreet.pop();
        }

        cout <<(possible ? "yes\n":"no\n");
    }

}