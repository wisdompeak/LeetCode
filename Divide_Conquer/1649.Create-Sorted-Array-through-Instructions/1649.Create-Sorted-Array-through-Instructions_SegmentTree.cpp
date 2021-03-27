class Solution {
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
            node->info = 0;
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
    
    void updateSingleBy(SegTreeNode* node, int id, int val)
    {        
        if (id < node->start || id > node->end ) return;
        if (node->start == node->end)
        {
            node->info += val;
            return;
        }
        updateSingleBy(node->left, id, val);
        updateSingleBy(node->right, id, val);
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
    
    long M = 1e9+7;
    
public:
    int createSortedArray(vector<int>& instructions) 
    {
        set<int>Set(instructions.begin(), instructions.end());
        unordered_map<int,int>num2idx;
        int i = 0;
        for (auto x:Set)
        {
            num2idx[x] = i;
            i++;
        }
        int n = num2idx.size();
                
        SegTreeNode* root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);
        
        long ret = 0;        
        for (auto x: instructions)
        {
            long a = queryRange(root, 0, num2idx[x]-1);
            long b = queryRange(root, num2idx[x]+1, n-1);
            ret += min(a,b);
            ret %= M;
            updateSingleBy(root, num2idx[x], 1);
        }
        return ret;        
    }
};
