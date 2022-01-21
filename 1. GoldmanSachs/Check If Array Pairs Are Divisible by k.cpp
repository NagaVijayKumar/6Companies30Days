class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Find the remainders of each num
        // remainder of (r) == remainder of (k-r),           
        // if r == 0, then it must be even
        
        // 43 11 22 19 88 37  k = 10
        // 3  1  2  9  8  7
        
        
        int n = arr.size();
        if(n%2!=0){
            return false;
        }
        
        unordered_map<int,int>freq;
        
        for(int i=0; i<n; i++){
            freq[(k+arr[i]%k)%k]++; // To handle negitive numbers, you must use (k+arr[i]%k)%k,    arr[i]%k only works for positive numbers
        }
        
        for(int i=0; i<n; i++){
            int r = (k+arr[i]%k)%k;
            
            if(r==0){
                if(freq[r]%2!=0){
                    return false;
                }
            }else if(freq[r]!=freq[k-r]){
                return false;
            }
        }
        
        return true;
    }
    
};
