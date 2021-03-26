// LeetCode 370. Range Addition

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
                
        node->info = node->left->info + node->right->info;  // write your own logic
    }
    
    void updateRangeBy(SegTreeNode* node, int a, int b, int val)
    {        
        if (b < node->start || a > node->end ) return;
        if (a <= node->start && node->end <=b)
        {
            // write your own logic            
            node->info += val * len(node);    
            node->tag += val;   
            return;
        }
        
        pushDown(node);        
        updateRangeBy(node->left, a, b, val);
        updateRangeBy(node->right, a, b, val);
        
        node->info = node->left->info + node->right->info;  // write your own logic
    }
    
    int len(SegTreeNode* node)
    {
        return node->end - node->start + 1;
    }
    
    void pushDown(SegTreeNode* node)
    {
        if (node->tag!=0)
        {
            node->left->info += len(node->left) * node->tag;
            node->right->info += len(node->right) * node->tag;
            node->left->tag += node->tag;
            node->right->tag += node->tag;
            node->tag = 0;
        }        
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
        return queryRange(node->left, a, b) + queryRange(node->right, a, b);  // write your own logic
    }    
    
    SegTreeNode* root;
    
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        SegTreeNode* root = new SegTreeNode(0, length-1);
        
        init(root, 0, length-1);
            
        for (auto& update: updates)
        {
            updateRangeBy(root, update[0], update[1], update[2]);            
        }
        vector<int>rets(length);
        for (int i=0; i<length; i++)
            rets[i] = queryRange(root, i, i);
        return rets;
    }
};
