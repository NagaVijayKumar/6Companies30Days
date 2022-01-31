// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    // step 1 : find freq 
		    // step 2 :    if freq == 1, (it is not repeating char) push into queue
		    // step 3 :   check the first non repeating char in que, if the pee ele is not first non repeating, pop from que
		    // step 3 : if queue is empty (we dont find first non repeating char) else peak_ele is first not repeating char
		    string res = "";
		    int n = A.size();
		    
		    vector<int>freq(26,0);
		    queue<char>que;
		    
		    
		    freq[A[0]-'a']++;
		    que.push(A[0]);
		    res = A[0];
		    
		    for(int i=1; i<n; i++){
		        freq[A[i]-'a']++;
		        
		        if(freq[A[i]-'a']==1){
		            que.push(A[i]);
		        }
		        
		        while(!que.empty()){
		            char peek_ele = que.front();
		            if(freq[peek_ele-'a']==1){
		                break;
		            }else{
		                que.pop();
		            }
		        }
		        
		        if(que.empty()){
		            res += "#";
		        }else{
		            res += que.front();
		        }
		        
		    }
		   
		   return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
