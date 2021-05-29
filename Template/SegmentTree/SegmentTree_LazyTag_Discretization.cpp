// LeetCode 699. Falling Squares

class Solution {
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;  // the max height of the range
        bool tag; 
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
                
        node->info = 0;  // write your own logic
    }
    
    void updateRange(SegTreeNode* node, int a, int b, int val)
    {        
        if (b < node->start || a > node->end ) // no intersection
            return;
        if (a <= node->start && node->end <=b)
        {
            node->info = val;
            node->tag = 1;
            return;
        }
        
        pushDown(node);        
        updateRange(node->left, a, b, val);
        updateRange(node->right, a, b, val);
        
        node->info = max(node->left->info, node->right->info);  // write your own logic
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
        pushDown(node);        
        return max(queryRange(node->left, a, b), queryRange(node->right, a, b));  // write your own logic        
    }    
    
    void pushDown(SegTreeNode* node)
    {
        if (node->tag==true)
        {
            node->left->info = node->info;
            node->right->info = node->info;
            node->left->tag = 1;
            node->right->tag = 1;
            node->tag = 0;
        }        
    }  
    
    
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) 
    {
        set<int>Set;
        for (auto & rect: positions)
        {
            Set.insert(rect[0]);
            Set.insert(rect[0]+rect[1]);
        }
        unordered_map<int,int>pos2idx;
        int idx = 0;
        for (auto x: Set)
        {
            pos2idx[x] = idx;
            idx++;
        }
        int n = pos2idx.size();
        
        SegTreeNode* root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);
        
        int maxH = 0;
        vector<int>rets;
        for (auto & rect: positions)
        {
            int a = pos2idx[rect[0]];
            int b = pos2idx[rect[0]+rect[1]];
            int h = queryRange(root, a, b-1);  // [a,b)
            updateRange(root, a, b-1, h + rect[1]);
            maxH = max(maxH, h + rect[1]);
            rets.push_back(maxH);
        }
        return rets;        
    }
};
