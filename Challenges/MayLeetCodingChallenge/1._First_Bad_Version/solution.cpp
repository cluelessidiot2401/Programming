// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    bool isBadVersion(int version);
public:
    int firstBadVersion(int n) {
        long low = 1, high = n;
        while(low <= high)
        {
            long mid = (low + high)/2;
            bool isMidBad = isBadVersion(mid);
            if(isMidBad && mid == low)
                return mid;
            if(isMidBad)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};