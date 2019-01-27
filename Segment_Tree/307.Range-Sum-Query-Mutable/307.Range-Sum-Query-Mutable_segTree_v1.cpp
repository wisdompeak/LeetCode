class NumArray {
    class SegmentTreeNode
    {
        public:
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        int start, end, sum;
        SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(NULL),right(NULL){}
    };
    SegmentTreeNode* root;
public:
    NumArray(vector<int> nums) 
    {
        int n=nums.size();
        root = buildTree(nums, 0, n-1);        
    }
    
    void update(int i, int val) 
    {
        modifyTree(root, i, val);
    }
    
    int sumRange(int i, int j) 
    {
        return queryTree(root, i, j);
    }
    
    SegmentTreeNode* buildTree(vector<int>&nums, int a, int b)
    {    
        if (a>b) return NULL; //这个很关键,因为不断地二分过程中会造成这种情况
        SegmentTreeNode* node = new SegmentTreeNode(a,b);
        if (a==b)
        {
            node->sum = nums[a];
            return node;
        }    
        node->left = buildTree(nums,a,(a+b)/2);
        node->right = buildTree(nums,(a+b)/2+1,b);
        node->sum = node->left->sum + node->right->sum;
        return node;    
    }
    
    void modifyTree(SegmentTreeNode* root, int i, int val)
    {
        if (root->start==i && root->end==i)
        {
            root->sum = val;
            return;
        }
        int mid = root->start + (root->end-root->start)/2;
        if (i<=mid)
            modifyTree(root->left,i,val);
        else
            modifyTree(root->right,i,val);
        root->sum = root->left->sum+root->right->sum;
    }
    
    int queryTree(SegmentTreeNode* root, int a, int b)
    {
        if (root->start==a && root->end==b) return root->sum;
        
        int mid = root->start+(root->end-root->start)/2;
        if (b<=mid)
            return queryTree(root->left, a, b);
        else if (a>mid)
            return queryTree(root->right, a, b);
        else
            return queryTree(root->left,a,mid)+queryTree(root->right,mid+1,b);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
