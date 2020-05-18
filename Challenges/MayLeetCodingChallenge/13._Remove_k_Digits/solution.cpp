#include <bits/stdc++.h>
using namespace std;

// static vector<int> trustCount=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return vector<int>(1001,0);
// }();
#define deb(x) cout << #x <<" = "<<x<<"; ";

class Solution {
public:
    Solution(){}
    string removeKdigits(string num, int k) {
        
        int i = 0, n = num.size();
        if(k == n)  return "0";

        string ans = "";
        for(; i < n; ++i)
        {
            while(k && ans.size() > 0 && ans.back() > num[i])    ans.pop_back(), --k;
            ans.push_back(num[i]);
        }
        i = 0, n = ans.size();
        while(i < n && ans[i] == '0')   ++i;
        
        if(i+k >= n)  return "0";
        return ans.substr(i, n-i-k);
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