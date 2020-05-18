// #include <iostream>
// #include <math.h>
//#include <bitset>
// #include <vector>
//#include <stdio.h>
//#include <algorithm>
//#include <string.h>
//#include <ctime>
#include <bits/stdc++.h>
using namespace std;


#define f(i,n)  for(int i=0;i<n;++i)
#define rf(i,n)  for(int i=n-1;i>=0;--i)
#define fab(i,a,b)	for(int i=a;i<=b;++i)
#define finc(i,a,b,in)	for(int i=a;i<=b;i+=in)
#define ll  long long
#define li long

#define sf(x)   scanf("%d",&x);
#define sfc(x)   scanf("%c",&x);
#define sfl(x)   scanf("%ld",&x);
#define sfll(x)   scanf("%lld",&x);

#define pf(x)   printf("%d",(int)x);
#define pfl(x)   printf("%ld",(long)x);
#define pfll(x)   printf("%lld",(long long)x);
#define pfs(x)   printf(x);
#define pfnl	printf("\n");

#define pii	pair<int,int>
#define ms(a,val,size)	memset(a,val,size*sizeof(typeof(*a)))
#define Mod (ll)(1e9+7)
#define INF 0x3f3f3f3f
#define pb push_back
#define MKSTR( x ) #x

#define seti(x) __builtin_popcount(x)	//No of Bits Set
#define setli(x) __builtin_popcountl(x)
#define setll(x) __builtin_popcountll(x)
#define numOfTrailingZeros(x)	__builtin_ctz(x)
#define numOfLeadingZeros(x)	__builtin_clz(x)
#define LSSetBit(x)	 __builtin_ffs(x)	//Returns position of least significant Set Bit in x eg 1 for 1
#define powi(x,y)	__builtin_powi(x,y)	//double,int : faster than pow; powif,powil
#define ispow2(x)	((x&(x-1)) == 0)	//Fails just for x==0
//#define ispow2(x)	(x && !(x & (x - 1)))
#define modIfPow2(n,d) (n&(d-1))	//	n%d  if ispow2(d)==1
#define fastIO 	ios::sync_with_stdio(false);cin.tie(0);//cout.tie(0);
#define deb(x) cout<<#x<<" = "<<x<<"; "

class Trie
{
    Trie* bits[2];
    int children;

    public:

    Trie(){
        children = 0;
        f(i,2) bits[i] = nullptr;
    }

    void insert(Trie* root, string binaryString)
    {
        // rf(i,binaryString.size())
        f(i,binaryString.size())
        {
            root->children++;
            if(root->bits[binaryString[i]-'0'] == nullptr)
                root->bits[binaryString[i]-'0'] = new Trie();
            root = root->bits[binaryString[i]-'0'];
        }
        root->children++;
    }

    ll toDecimal(string binary)
    {
        ll ans = 0;
        ll val = 1;
        rf(i, binary.size()){
            ans += val*(binary[i]-'0');
            val *= 2;
        }
        return ans;
    }

    long long getValue(Trie* root, string s)
    {
        string ans = "";
        // rf(i,s.size())
        f(i,s.size())
        {
            if(s[i] == '0')
            {
                if(root->bits[1] != nullptr)
                    root = root->bits[1], ans += '1' ;
                else if(root->bits[0] != nullptr)
                    root = root->bits[0], ans += '0';
                else return toDecimal(ans);
            }
            else
            {
                if(root->bits[0] != nullptr)
                    root = root->bits[0], ans += '0';
                else if(root->bits[1] != nullptr)
                    root = root->bits[1], ans += '1';
                else return toDecimal(ans);
            }
        }

        while(root->children != 0)
        {
            if((root->bits[1] != nullptr && root->bits[0] != nullptr && root->bits[1]->children >= root->bits[0]->children )
            || (root->bits[1] != nullptr && root->bits[0] == nullptr)
            )
            {
                root = root->bits[1];
                ans += '1';
            }
            else if((root->bits[0] != nullptr && root->bits[1] != nullptr && root->bits[0]->children > root->bits[1]->children )
            || (root->bits[0] != nullptr && root->bits[1] == nullptr))
            {
                root = root->bits[0];
                ans += '0';
            }
            else break;
        }

        return toDecimal(ans);
    }
};

// #define toBinary(x,noOfBits)	std::bitset<noOfBits>(x)
string toBinary(ll x, int noOfBits = 64)
{
    string ans = bitset<64>(x).to_string();
    if(noOfBits == 64)  return ans;
    else return ans.substr(64 - noOfBits);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin>>t;

    // int a[100000];

    while(t--)
    {
        int n;
        cin>>n;
        ll _xor = -1;
        Trie* root = new Trie();
        f(i,n){
            // cin>>a[i];
            int temp;
            cin>>temp;
            string binaryString = toBinary(temp);

            ll tempVal = root->getValue(root, binaryString);
            ll tempXor = tempVal ^ temp;

            if(i>0)
                _xor = max(_xor, tempXor);
            root->insert(root, binaryString);

            deb(temp); deb(binaryString); deb(tempVal); deb(tempXor); deb(_xor); cout<<'\n';
        }
        cout << _xor << '\n';
    }

}