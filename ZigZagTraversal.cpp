/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
           return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        q.push(root);
        bool level=false;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* p=q.front();
                temp.push_back(p->val);
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            if(level)
                reverse(temp.begin(),temp.end());
            level=!level;
            ans.push_back(temp);
        }
        
        return ans;
    }
};
