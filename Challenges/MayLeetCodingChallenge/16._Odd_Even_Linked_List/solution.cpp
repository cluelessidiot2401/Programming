#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;++i)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define deb(x)  cout << #x << " = " << x << "; ";

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static int _ = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)    return head;
        
        ListNode* even = head->next;
        ListNode* ptr[2] = {head->next, head};
        bool cur = false;
        
        if(ptr[cur] != nullptr){
            while(true){
                if(ptr[cur]->next == nullptr)   break;
                ptr[!cur]->next = ptr[cur]->next;
                ptr[!cur] = ptr[!cur]->next;
                cur = !cur;
            }
        }
        
        ptr[1]->next = even;
        if(ptr[0] != nullptr)
            ptr[0]->next = nullptr;
        
        return head;
        
    }
};