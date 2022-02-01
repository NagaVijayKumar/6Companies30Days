/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
  
   
public:
 //Construct Tree from que
      TreeNode* makeTree(queue<string>&q){           // we call this recursively, so pass &q(queue<string>&q)  not just q(queue<string>q)
        
        string s = q.front();
        q.pop();
        if(s=="null"){
            return NULL;
        }
        
        TreeNode *root = new TreeNode(stoi(s));
        
        root->left = makeTree(q);
        root->right = makeTree(q);       
        
        return root;
     
       
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // PreOrder 
        if(!root){
            return "null,";
        }
        return to_string(root->val)+","+ serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //Get nodes for data;
        queue<string>q;
        string temp = "";
        for(char ch:data){
            if(ch==','){
                q.push(temp);
                temp = "";
                continue;
            }
            
            temp += ch; //it is to add 1(one) and 2(two) to make 12(twelve)
        }
        //Now make Tree
        return makeTree(q);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
