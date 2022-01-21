class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // find the sum in a window,
        // if curr_sum is > than target, decrease window size
        int min_len = INT_MAX, curr_len = 0, l = 0, r = 0, n = nums.size();
        int curr_sum = 0;
        
        while(l<n && r<n){
            curr_sum += nums[r];
            r++;
            while(curr_sum>=target){
                min_len = min(min_len, r-l);
                curr_sum -= nums[l];
                l++;
            }
        }
        
        if(min_len==INT_MAX){
            return 0;
        }
        return min_len;
    }
};
