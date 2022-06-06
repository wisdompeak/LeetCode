// 支持动态增减节点

class SegTree
{
    public:
    int start, end;
    bool status;
    SegTree* left;
    SegTree* right;
    SegTree(int a, int b, bool T):start(a),end(b),status(T),left(NULL),right(NULL){}

    void remove(SegTree* &node)
    {
        if (node==NULL) return;
        remove(node->left);
        remove(node->right);
        delete node;
        node = NULL;
        return;
    }

    void setStatus(int a, int b, bool T)
    {
        if (a<=start && b>=end) // bottom condition 1: [a,b)>[start,end)
        {
            remove(left);
            remove(right);
            status = T;
            return;
        }
        if (a>=end || b<=start) // bottom condition 2: [a,b) do not intersect with [start,end)
            return;
        int mid = start+(end-start)/2;
        if (left==NULL)         // no children? create them!
        {
            left = new SegTree(start,mid,status);
            right = new SegTree(mid,end,status);
        }
        left->setStatus(a,b,T);
        right->setStatus(a,b,T);
        status =left->status && right->status;
    }        

    bool getStatus(int a, int b)
    {            
        if (a<=start && b>=end)   // bottom condition 1: [a,b)>[start,end)
            return status;
        if (a>=end || b<=start)     // bottom condition 2: [a,b) do not intersect with [start,end)
            return true;
        if (left==NULL)
            return status;
        int mid = start+(end-start)/2;
        bool L = left->getStatus(a,b);
        bool R = right->getStatus(a,b);
        return L&&R;
    }        
};

class RangeModule {
public:
    
    SegTree root = SegTree(0,1e9,false);
    
    RangeModule() 
    {
    }
    
    void addRange(int left, int right) 
    {
        root.setStatus(left,right,true);
    }
    
    bool queryRange(int left, int right) 
    {        
        return root.getStatus(left,right);
    }
    
    void removeRange(int left, int right) 
    {
        root.setStatus(left,right,false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
