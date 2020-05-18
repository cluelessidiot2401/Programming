#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for(char c : J) jewels.insert(c);
        int count = 0;
        for(char s : S) if(jewels.find(s) != jewels.end())  ++count;
        return count;
    }
};