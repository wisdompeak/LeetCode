class Solution {
    class SegTree
    {
        public:
        int start,end,status;
        SegTree* left;
        SegTree* right;
        SegTree(int a, int b, int s):start(a),end(b),status(s),left(NULL),right(NULL){}
        
        void setStatus(int a, int b, int s)
        {
            if (a<=start && b>=end && left==NULL)   // bottom node condition 1;
            {
                status += s;
                return;
            }
            if (a>=end || b<=start)         // bottom node condition 2;
                return;
            int mid = start+(end-start)/2;  
            if (left==NULL)                 // no children? create them
            {
                left = new SegTree(start,mid,status);
                right = new SegTree(mid,end,status);
            }                               // recursion
            left->setStatus(a,b,s);
            right->setStatus(a,b,s);
        }
    };
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        SegTree* root = new SegTree(0,length,0);
        for (auto x:updates)        
            root->setStatus(x[0],x[1]+1,x[2]);
        vector<int>results(length);
        DFS(root,results);
        return results;
    }
    void DFS(SegTree* node, vector<int>&results)
    {
        if (node->left!=NULL)
        {
            DFS(node->left,results);
            DFS(node->right,results);
            return;
        }
        for (int i=node->start; i<node->end; i++)
            results[i] = node->status;
    }
};
