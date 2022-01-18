string encode(string src){     
   //Your code here 
   string s = "";
   int i=0, j=0;
   int n = src.length();
   
   while(i<n){
       while(src[i] == src[j] and j<n){
           j++;
       }
       
       s.push_back(src[i]);
       s += to_string(j-i);
       
       i = j;
   }
   return s;
   
}  

