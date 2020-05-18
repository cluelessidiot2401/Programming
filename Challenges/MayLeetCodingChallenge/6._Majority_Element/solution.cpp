#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n = nums.size();
        // Moore's voting algorithm
        
        int candidate_elem_for_majority = nums[0], count = 1;
        for(int i = 1;i<n;++i)
        {
            if(nums[i] == candidate_elem_for_majority) ++count;
            else
            {
                --count;
                if(count == 0)  candidate_elem_for_majority = nums[i], count = 1;
            }
        }
        // No need to check if candidate elem is actually majority element since it is given that there will always be a majority elem
        return candidate_elem_for_majority;
    }
};