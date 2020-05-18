#include <bits/stdc++.h>
using namespace std;

// static vector<int> trustCount=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return vector<int>(1001,0);
// }();
#define deb(x) cout << #x <<" = "<<x<<"; ";

#define pp pair<char,int>
class Solution {
public:
    Solution(){}
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        
        int i = 0, cnt = k;
        char last = '0';
        stack<pp> st;
        while(i<n){
            if(num[i] >= last){
                last = num[i];
                st.push({last, i});
            }else   break;
            ++i;
        }
        
        cnt = k;
        i = 0;
        while(!st.empty() && cnt--)
        {
            pp cur = st.top();
            st.pop();
            num[cur.second] = 'x';
            
            i = 0;
            while(i<n && (num[i] == 'x' || num[i] == '0'))    num[i++] = 'x';
            if(cnt == 0)    break;
            
            if(st.empty()){
                last = '0';
            }
            else{
                last = st.top().first;
            }
            
            i = cur.second + 1;
            while(i<n){
                if(num[i] == 'x'){
                    ++i;
                    continue;
                }
                if(num[i] >= last){
                    last = num[i];
                    st.push({last, i});
                }else   break;
                ++i;
            }
        }
        string ans = "";
        i = 0;
        while(i < n){
            if(num[i] != 'x')   ans += num[i];
            ++i;
        }
        if(ans == "")   ans = "0";
        return ans;
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    string s;
    int k;
    cin>>s>>k;
    s = s.substr(1, s.size() - 2);
    Solution solution = Solution();
    cout << solution.removeKdigits(s, k) << '\n';
}