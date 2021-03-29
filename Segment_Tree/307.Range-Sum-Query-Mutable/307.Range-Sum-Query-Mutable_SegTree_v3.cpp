class NumArray {
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;        
        SegTreeNode(int a, int b):start(a),end(b),info(0),left(NULL),right(NULL){}
    };
    
    void init(SegTreeNode* node, int a, int b)  // init for range [a,b]
    {                        
        if (a==b)
        {
            node->info = nums[a];
            return;
        }
        int mid = (a+b)/2;
        if (node->left==NULL)
        {
            node->left = new SegTreeNode(a, mid);
            node->right = new SegTreeNode(mid+1, b);
        }
        init(node->left, a, mid);
        init(node->right, mid+1, b);
                
        node->info = node->left->info + node->right->info;  // write your own logic
    }
    
    void updateSingle(SegTreeNode* node, int id, int val)
    {        
        if (id < node->start || id > node->end ) return;
        if (node->start == node->end)
        {
            node->info = val;
            return;
        }
        updateSingle(node->left, id, val);
        updateSingle(node->right, id, val);
        node->info = node->left->info + node->right->info;  // write your own logic
    }
    
    int queryRange(SegTreeNode* node, int a, int b)
    {
        if (b < node->start || a > node->end )
        {
            return 0;  // write your own logic
        }
        if (a <= node->start && b>=node->end)
        {
            return node->info;  // write your own logic
        }        
        return queryRange(node->left, a, b) + queryRange(node->right, a, b);  // write your own logic
    }    
    
    vector<int> nums;
    SegTreeNode* root;
    
public:
    NumArray(vector<int> nums) 
    {
        this->nums = nums;
        root = new SegTreeNode(0, nums.size()-1);
        init(root, 0, nums.size()-1);
    }
    
    void update(int i, int val) 
    {
        updateSingle(root, i, val);        
    }
    
    int sumRange(int i, int j) 
    {
        return queryRange(root, i, j);
    }
};
