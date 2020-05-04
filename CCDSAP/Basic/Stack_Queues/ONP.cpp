// https://www.spoj.com/problems/ONP/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <unordered_map>
#include <stack>
using namespace std;
typedef long long ll;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define rfab(i,a,b) for(int i=a;i>=b;--i)
#define MAX_LEN (int)(1e6)
#define TOTAL_OPERANDS 5

char operands[10] = {'+', '-', '*', '/', '^'};

bool isOperand(char c)
{
    f(i, TOTAL_OPERANDS)
        if(c == operands[i])
            return true;
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	int t;
    cin>>t;

    unordered_map<char, int> precedence;
    f(i,TOTAL_OPERANDS)
        precedence[operands[i]] = i;
    
    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();
        stack<char> st;
        f(i,n)
        {
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    cout<< st.top();
                    st.pop();
                }
                if(st.top() == '('){
                    st.pop();
                }   
            }
            else if(isOperand(s[i])){

                if(st.empty() || st.top() == '(' || precedence[s[i]] > precedence[st.top()]){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && st.top() != '(' && precedence[st.top()] >= precedence[s[i]]){
                        cout<<st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            else{
                cout<<s[i];
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<'\n';
    }

}