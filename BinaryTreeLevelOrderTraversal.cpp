//Binary Tree Level Order Traversal
//timec: O(n)   //O(2n)?
//space: O(n)   //O(two layers)?
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int> > vv;
        
        if(!root)
          return vv;
          
        queue<TreeNode* > q1;
        queue<TreeNode* > q2;
        
        q1.push(root);
        
        while(!q1.empty() || !q2.empty())
        {
            vector<int> v;
            while(!q1.empty())
            {
                TreeNode* nodeT=q1.front();
                v.push_back(nodeT->val);
                q1.pop();
                if(nodeT->left)
                  q2.push(nodeT->left);
                if(nodeT->right)
                  q2.push(nodeT->right);
            }
            
            if(!v.empty())
              vv.push_back(v);
              
            v.clear();
            
            while(!q2.empty())
            {
                TreeNode* nodeT=q2.front();
                v.push_back(nodeT->val);
                q2.pop();
                if(nodeT->left)
                  q1.push(nodeT->left);
                if(nodeT->right)
                  q1.push(nodeT->right);
            }
            
            if(!v.empty())
              vv.push_back(v);
              
            v.clear();
        }
        
        return vv;
    }
};
