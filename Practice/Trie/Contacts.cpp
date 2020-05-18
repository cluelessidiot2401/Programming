// https://www.hackerrank.com/challenges/contacts/problem
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


class Trie
{
    Trie* next[26];
    int children;

    public:

    Trie(){
        children = 0;
        f(i,26) next[i] = nullptr;
    }

    static Trie* head;

    void insert(string s)
    {
        Trie* cur = head;
        f(i,s.size())
        {
            cur->children++;
            if(cur->next[s[i]-'a'] == nullptr)
                cur->next[s[i]-'a'] = new Trie();
            cur = cur->next[s[i]-'a'];
        }
        cur->children++;
    }

    int getPartialCount(string s)
    {
        Trie* cur = head;
        f(i,s.size())
        {
            if(cur->next[s[i]-'a'] == nullptr)
                return 0;
            cur = cur->next[s[i]-'a'];
        }
        return cur->children;
    }
};

Trie* Trie::head = new Trie();
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n;
    // read(n);
    cin>>n;

    f(i,n)
    {
        string op, str;
        // read(op, str);
        cin>>op>>str;
        if(op == "add")
            Trie::head->insert(str);
        else{
            cout<< Trie::head->getPartialCount(str) <<'\n';
        }
    }

}