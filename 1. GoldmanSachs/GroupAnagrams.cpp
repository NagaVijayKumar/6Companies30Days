class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // after sorting if two strings are equal, then they are anagrams
        // create unorderd_map make sorting str as key, if the same key is come againg append to it
        // unordered_map<string,vector<string>>hash
        
        int n = strs.size();
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>>hash;
        
        for(int i=0; i<n; i++){
            
            string val = strs[i];
            
            sort(strs[i].begin(), strs[i].end());//sorting str is same if two strngs are anagrams, so use sorting str as key in hash map
            
            hash[strs[i]].push_back(val);
        }
        
        //store res
        
        for(auto it:hash){
            res.push_back(it.second);
        }
        
        return res;
        
    }
};
