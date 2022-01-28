class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size(), maxMountainHeight = 0;
        
        if(n<3){
            return 0;
        }
        
        int i=1;
        
        while(i<n){
            
            //if two adjacent eles are equal, increament pointer
            while(i<n && arr[i]==arr[i-1]){
                i++;
            }
            
            //increasing up cnt, untill it reaches mountain peak
            int up = 0;
            while(i<n && arr[i-1]<arr[i]){
                i++;
                up++;
            }
            
            //increase down cnt, untill it reach mountain vally
            int down = 0;
            while(i<n && arr[i-1]>arr[i]){
                i++;
                down++;
            }            
            
            
            //if both both up and exists then only, mountain exists
            if(up!=0 && down!=0){
                maxMountainHeight = max(maxMountainHeight, up+down+1);
            }
        
        }
        
        return maxMountainHeight;
    }
};
