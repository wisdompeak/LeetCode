class Solution {
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    long M = 1e9+7;
    long comb[1001][1001];

    long getComb(long m, long n)
    {
        if (comb[m][n]!=-1)
            return comb[m][n];
        if (n==0) return 1;
        if (n==1) return m;        
        if (n>m-n) return getComb(m, m-n);
        long a = getComb(m-1, n-1);        
        long b = getComb(m-1, n);
        comb[m][n] = (a+b)%M;
        return comb[m][n];
    }
    
public:
    int numOfWays(vector<int>& nums) 
    {
        for (int i=0; i<=1000; i++)
            for (int j=0; j<=1000; j++)
                comb[i][j] = -1;
        
        TreeNode* root = new TreeNode(nums[0]);
        for (int i=1; i<nums.size(); i++)        
            insertNode(root, nums[i]);
                    
        long num, val;
        dfs(root, num, val);
        return val-1;
    }

    void insertNode(TreeNode* root, int val)
    {
        if (val < root->val)
        {
            if (root->left==NULL)
                root->left = new TreeNode(val);
            else
                insertNode(root->left, val);
        }
        else
        {
            if (root->right==NULL)
                root->right = new TreeNode(val);
            else
                insertNode(root->right, val);
        }
    }
    
    void dfs(TreeNode* node, long& num, long& val)
    {
        if (node->left==NULL && node->right==NULL)
        {
            num = 1;
            val = 1;
            return;
        }
        
        long leftNum = 0, leftVal = 1;
        long rightNum = 0, rightVal = 1;
        if (node->left)
            dfs(node->left, leftNum, leftVal);
        if (node->right)
            dfs(node->right, rightNum, rightVal);
        
        num = leftNum+rightNum+1;
        val = ((getComb(leftNum+rightNum, leftNum) * leftVal) % M * rightVal) % M;
        return;        
    }
};
