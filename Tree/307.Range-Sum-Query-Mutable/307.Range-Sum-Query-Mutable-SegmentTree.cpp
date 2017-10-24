class NumArray {
    class SegmentTreeNode 
    {
        public:
        int start, end, sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(NULL),right(NULL){}
    };
    SegmentTreeNode* root;
    
public:
    NumArray(vector<int> nums) 
    {
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }
    
    void update(int i, int val) 
    {
        modifyTree(i,val,root);
    }
    
    int sumRange(int i, int j) 
    {
        return queryTree(i, j, root);
    }
    
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) 
    {
        if(start > end) return NULL;
        
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        
        if(start == end) 
        {
            root->sum = nums[start];
            return root;
        }        
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    void modifyTree(int i, int val, SegmentTreeNode* root) 
    {
        if(root == NULL) return;
        
        if (root->start == i && root->end == i) 
        {            
            root->sum = val;
            return;
        }
        if (root->start > i || root->end < i)
            return;
        
        int mid = (root->start + root->end) / 2;
        if (i > mid) 
            modifyTree(i,val,root->right);        
        else 
            modifyTree(i,val,root->left);        
        root->sum = root->left->sum + root->right->sum;        
    }    
    
    int queryTree(int i, int j, SegmentTreeNode* root) 
    {
        if(root == NULL) return 0;
        if (i<root->start || j>root->end) return 0;    
        if(root->start == i && root->end == j) 
            return root->sum;
        
        int mid = (root->start + root->end) / 2;
        if (i > mid) 
            return queryTree(i,j,root->right);
        else if(j <= mid) 
            return queryTree(i,j,root->left);
        else
            return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
