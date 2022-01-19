class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Find product in a window range
        if(k<=1){
            return 0;
        }
        int n = nums.size();
        int left = 0, prod = 1;
        int cnt = 0;
        
        for(int right = 0; right<n; right++){
            prod *= nums[right];
            
            while(prod>=k){
                prod /= nums[left];
                left++;
            }
            
            cnt += (right-left+1);
        }
        
        return cnt;
        
    }
};
