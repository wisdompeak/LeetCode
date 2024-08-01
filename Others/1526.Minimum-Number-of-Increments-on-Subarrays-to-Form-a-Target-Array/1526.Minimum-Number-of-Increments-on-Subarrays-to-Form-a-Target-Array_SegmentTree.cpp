class Solution {
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info, pos;               
        SegTreeNode(int a, int b):start(a),end(b),info(0),pos(0),left(NULL),right(NULL){}
    };
    
    void init(SegTreeNode* node, int a, int b)  // init for range [a,b]
    {                        
        if (a==b)
        {
            node->info = target[a];
            node->pos = a;
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
                
        if (node->left->info < node->right->info)
        {
            node->info = node->left->info;
            node->pos = node->left->pos;
        }
        else
        {
            node->info = node->right->info;
            node->pos = node->right->pos;
        }
    }
    
    pair<int,int> queryRangeMin(SegTreeNode* node, int a, int b)
    {        
        if (b < node->start || a > node->end )
        {
            return {INT_MAX, a}; // write your own logic
        }
        if (a <= node->start && b>=node->end)
        {
            return {node->info, node->pos};  // write your own logic
        }  
        
        auto L = queryRangeMin(node->left, a, b);
        auto R = queryRangeMin(node->right, a, b);
        
        if (L.first < R.first)
            return L;
        else
            return R;
    }    
    
    SegTreeNode* root;        
    vector<int> target;
    
public:
    int minNumberOperations(vector<int>& target) 
    {
        this->target = target;        
        int n = target.size();
        
        root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);        
        
        return DFS(target, 0, 0, n-1);
    }
    
    int DFS(vector<int>& target, int base, int a, int b)
    {
        if (a>b) return 0;
        if (a==b) return target[a] - base;
                
        auto [val, pos] = queryRangeMin(root, a, b);        
        int sum = val - base;
        sum += DFS(target, val, a, pos-1);
        sum += DFS(target, val, pos+1, b);    
        return sum;
    }
};
