class Solution {
class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;       
        int tag;
        SegTreeNode(int a, int b):start(a),end(b),info(0),tag(0),left(NULL),right(NULL){}
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
    }
    
    int queryRange(SegTreeNode* node, int a, int b)
    {
        if (b < node->start || a > node->end ) // no intersection
            return 0;
        if (node->start == node->end)   // leaf node, no need to dive
        {                        
            return node->info;
        }
        if (a <= node->start && node->end <=b && node->tag) // lazy tagged, no need to dive
        {
            return node->info;
        }
        if (node->tag)
        {
            node->tag = 0;
            node->left->info = node->info;
            node->right->info = node->info;
            node->left->tag = 1;
            node->right->tag = 1;            
        }
        return max(queryRange(node->left, a, b), queryRange(node->right, a, b));
    }
    
    void updateRange(SegTreeNode* node, int a, int b, int val)
    {        
        if (b < node->start || a > node->end ) // no intersection
            return;
        if (node->start == node->end)   // leaf node, no need to dive
        {
            node->info = val;
            node->tag = 0;
            return;
        }
        if (a <= node->start && node->end <=b) // no need to dive, tag lazy
        {            
            node->info = val;
            node->tag = 1;
            return;
        }
        
        if (node->tag == 1) // if current node tagged lazy, push information down
        {
            node->tag = 0;            
            node->left->info = node->info;
            node->right->info = node->info;
            node->left->tag = 1;
            node->right->tag = 1;            
        }        
        node->info = val;
        
        updateRange(node->left, a, b, val);
        updateRange(node->right, a, b, val);        
    }
        
    SegTreeNode* root;    
    
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) 
    {
        unordered_map<int,int>pos2idx;
        set<int>Set;
        for (auto & rect: positions)
        {
            Set.insert(rect[0]);
            Set.insert(rect[0]+rect[1]);        
        }
        int i = 0;
        for (auto x: Set)
        {
            pos2idx[x] = i;
            i++;
        }
        
        int n = pos2idx.size();
        SegTreeNode* root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);
        
        int cur = 0;
        vector<int>rets;
        for (auto& rect: positions)
        {
            int a = pos2idx[rect[0]], b = pos2idx[rect[0]+rect[1]];
            int h = queryRange(root, a, b-1);
            updateRange(root, a, b-1, h+rect[1]);
            cur = max(cur, h+rect[1]);
            rets.push_back(cur);
        }
        return rets;        
    }
};
