class Solution {
public:
    vector<int> output;
    void getElements(TreeNode* root, vector<int>& output ){
       if(!root) return;
        getElements(root->left, output);
        output.emplace_back(root->val);
      getElements(root->right,output);  
    } 
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       getElements(root1,output);
        getElements(root2, output);
        sort(output.begin(),output.end());
        return output;
    }
};
