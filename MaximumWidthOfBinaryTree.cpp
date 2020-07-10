class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int res=0;
        
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,1));
        
        while(!q.empty())
        {
            
            int ct=q.size();
            
            res=max(res,q.back().second-q.front().second+1);
            
            while(ct--)
            {
                pair<TreeNode*,int>p=q.front();
                q.pop();
            
                if(p.first->left!=NULL)
                {
                    q.push(make_pair(p.first->left,2*(long long)p.second));
                }
                if((p.first->right!=NULL)
                {
                    q.push(make_pair(p.first->right,2*(long long)p.second)+1);
                }  
            }
        }
                   
        return result;
    }
};
