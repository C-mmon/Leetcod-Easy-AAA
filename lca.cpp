/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //BASE CASE WHY? !ROOT n
        if(!root || root==p || root==q)
        {
            return root;
        }
        
        
        //BASICALLY GOING LEFT AND RIGHT EASY ?
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        
        //UH OH DEAD END BACK TRACK
        if(left == NULL && right == NULL) return NULL; 
        
        //FINALLY SOME CANDIDATE
        if(left != NULL && right != NULL) return root;  
        
        //MUST BE EITHER OF THEM 
        return left == NULL ? right : left;
    }
};