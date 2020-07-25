class Solution {
    class SegmentTreeNode
    {
        public:
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        int start, end, val, pos;
        SegmentTreeNode(int a, int b):start(a),end(b),val(0),left(NULL),right(NULL){}
    };
    SegmentTreeNode* root;
    
    SegmentTreeNode* buildTree(vector<int>&nums, int a, int b)
    {    
        if (a>b) return NULL; 
        SegmentTreeNode* node = new SegmentTreeNode(a,b);
        if (a==b)
        {
            node->val = nums[a];
            node->pos = a;
            return node;
        }    
        node->left = buildTree(nums,a,(a+b)/2);
        node->right = buildTree(nums,(a+b)/2+1,b);
        if (node->left->val <= node->right->val)
        {
            node->val = node->left->val;
            node->pos = node->left->pos;
        }
        else
        {
            node->val = node->right->val;
            node->pos = node->right->pos;
        }        
        return node;    
    }
    
    pair<int,int> queryTree(SegmentTreeNode* root, int a, int b)
    {
        if (root->start==a && root->end==b) return {root->val, root->pos};
        
        int mid = root->start+(root->end-root->start)/2;
        if (b<=mid)
            return queryTree(root->left, a, b);
        else if (a>mid)
            return queryTree(root->right, a, b);
        else
        {
            auto L = queryTree(root->left,a,mid);
            auto R = queryTree(root->right,mid+1,b);
            if (L.first<=R.first) return L;
            else return R;            
        }        
    }
    
    int ret = 0;
    
public:
    int minNumberOperations(vector<int>& target) 
    {
        int n=target.size();
        root = buildTree(target, 0, n-1);  
        
        DFS(0,n-1, 0);
        return ret;
    }
    
    void DFS(int a, int b, int cur)
    {
        // cout<<a<<" "<<b<<" "<<cur<<endl;
        if (a>b) return;
        auto x = queryTree(root, a, b);
        int val = x.first;
        int pos = x.second;
        if (val!=cur)
            ret += (val-cur);
        DFS(a, pos-1, val);
        DFS(pos+1, b, val);            
    }
};
