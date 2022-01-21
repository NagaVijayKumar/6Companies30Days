class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing_num = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            missing_num ^= nums[i] ^ (i+1);
        }
        return missing_num;
    }
};
