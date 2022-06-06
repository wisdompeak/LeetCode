// 线段树可动态开点

class SegTree
{
    public:
    int start,end,status;
    SegTree* left;
    SegTree* right;
    SegTree(int a,int b,int s):start(a),end(b),status(s),left(NULL),right(NULL){}

    void remove(SegTree* &node)
    {
        if (node==NULL) return;
        remove(node->left);
        remove(node->right);
        delete node;
        node=NULL;
        return;
    }

    void setStatus(int a, int b, int s)
    {
        if (a<=start && b>=end)
        {
            remove(left);
            remove(right);
            status = s;
            return;
        }
        if (a>=end || b<=start)
            return;
        if (left==NULL)
        {
            int mid = (end-start)/2+start;
            left = new SegTree(start,mid,status);
            right = new SegTree(mid,end,status);
        }
        left->setStatus(a,b,s);
        right->setStatus(a,b,s);
        status = max(left->status,right->status);
        return;
    }

    int getStatus(int a, int b)
    {
        if (a<=start && b>=end)
            return status;
        if (a>=end || b<=start)
            return 0;
        if (left==NULL)
            return status;
        int L = left->getStatus(a,b);
        int R = right->getStatus(a,b);
        return max(L,R);            
    }        
};

class Solution {       
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) 
    {
        SegTree* root = new SegTree(0,1e9,0);
        vector<int>result;
        int curMax = 0;
        for (auto p:positions)
        {
            int cur = root->getStatus(p[0], p[0]+p[1]);
            curMax = max(curMax, cur+p[1]);
            root->setStatus(p[0], p[0]+p[1], cur+p[1]);            
            result.push_back(curMax);                    
        }
        return result; 
    }
};
