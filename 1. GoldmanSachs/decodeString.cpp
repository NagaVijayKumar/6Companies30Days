class Solution {
public:
    string decodeString(string s) {
        
        stack<char>stk;
         string temp1 = "";
        for(char ch: s){
            if(ch!=']'){
                stk.push(ch);
            }else if(ch==']'){
                string temp = "";
                
                while(!stk.empty() && stk.top()!='['){
                    temp += stk.top();
                    stk.pop();
                }
                // remove [
                stk.pop();
                
                reverse(temp.begin(), temp.end());
                vector<int>num_arr;
                int num = 0;
                while(!stk.empty() && isdigit(stk.top())){
                    num_arr.push_back(stk.top()-'0');
                    // num = (num*10) + (stk.top()-'0');
                    stk.pop();
                }
                
                for(int i=0; i<num_arr.size(); i++){
                    num = num + (pow(10,i)*num_arr[i]);
                }
                temp1 = "";
                for(int i=0; i<num; i++){
                    temp1 += temp;
                }
                
                for(char ch: temp1){
                    stk.push(ch);
                }
                
                
            }
           
        }
        
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
