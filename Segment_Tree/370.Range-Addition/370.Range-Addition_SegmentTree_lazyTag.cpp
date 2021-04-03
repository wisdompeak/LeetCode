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
                
        node->info = 0;  // write your own logic
    }
    
    void updateRange(SegTreeNode* node, int a, int b, int val)
    {
        if (b < node->start || a > node->end )
            return;
        if (a <= node->start && b>=node->end)
        {
            node->info += val * (node->end-node->start+1);
            node->tag += val;
            return;
        }
        
        pushdown(node); // erase lazy tag and propagate down
        updateRange(node->left, a, b, val);
        updateRange(node->right, a, b, val);
    }
    
    void pushdown(SegTreeNode* node)
    {
        if (node->tag != 0)
        {
            node->left->tag += node->tag;
            node->right->tag += node->tag;
            node->left->info += node->tag * (node->left->end-node->left->start+1);
            node->right->info += node->tag * (node->right->end-node->right->start+1);
            node->tag = 0;            
        }
    }
    
    int querySingle(SegTreeNode* node, int id)
    {
        if (id < node->start || id > node->end )
        {
            return INT_MAX;  // write your own logic
        }
        if (node->start==id && node->end==id)
        {
            return node->info;
        }
        
        pushdown(node);
        int a = querySingle(node->left, id);
        int b = querySingle(node->right, id);
        if (a!=INT_MAX) return a;
        else if (b!=INT_MAX) return b;
        else return INT_MAX;
    }
    
    
    
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        SegTreeNode* root = new SegTreeNode(0, length-1);
        init(root, 0, length-1);
        
        for (auto update: updates)
        {
            updateRange(root, update[0], update[1], update[2]);
        }
        
        vector<int>rets(length);
        for (int i=0; i<length; i++)
        {
            rets[i] = querySingle(root, i);
        }
            
        return rets;
    }
};

