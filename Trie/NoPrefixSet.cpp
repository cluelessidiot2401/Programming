// https://www.hackerrank.com/challenges/no-prefix-set/problem
/*
4
aa
a
BAD SET
a
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


class Trie
{
    Trie* next[26];
    bool endsHere;

    public:

    Trie(){
        f(i,26) next[i] = nullptr;
        endsHere = false;
    }

    static Trie* head;

    bool insert(string s)
    {
        Trie* cur = head;
        f(i,s.size())
        {
            if(cur->endsHere || (i == s.size() - 1 && cur->next[s[i]-'a'] != nullptr))
                return false;
            if(cur->next[s[i]-'a'] == nullptr)
                cur->next[s[i]-'a'] = new Trie();
            cur = cur->next[s[i]-'a'];
        }
        cur->endsHere = true;
        return true;
    }
};

Trie* Trie::head = new Trie();
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

    int n;
    cin>>n;

    bool good = true;
    f(i,n)
    {
        string str;
        cin>>str;
        if(good)
        {
            bool isGood = Trie::head->insert(str);
            if(!isGood)
            {
                cout<<"BAD SET\n"<<str;
                good = false;
            }
        }
    }
    if(good)    cout<<"GOOD SET\n";

}