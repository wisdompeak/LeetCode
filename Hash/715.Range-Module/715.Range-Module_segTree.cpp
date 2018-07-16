class RangeModule {
    class SegTree
    {
        public:
        int begin, end;
        SegTree* left;
        SegTree* right;
        bool tracked;
        SegTree(int a, int b, bool T)
        {
            begin = a;
            end = b;            
            tracked = T;
            left = NULL;
            right = NULL;
        }                
        
        void remove(SegTree* &node)
        {
            if (!node) return;
            remove(node->left);
            remove(node->right);
            delete node;
            node = NULL;
        }
        
        bool setTracking(int a, int b, bool tracking)
        {
            if (a<=begin && end<=b)
            {
                remove(left);
                remove(right);
                return tracked = tracking;
            }
            int mid = (end-begin)/2+begin;
            if (!left)
            {
                left = new SegTree(begin,mid,tracked);
                right = new SegTree(mid,end,tracked);
            }
            bool leftTracked, rightTracked;
            if (a<mid)            
                leftTracked = left->setTracking(a,b,tracking);
            else
                leftTracked = left->tracked;
            if (b>mid)
                rightTracked = right->setTracking(a,b,tracking);
            else
                rightTracked = right->tracked;
            return tracked = leftTracked && rightTracked;
        }
        
        bool getTracking(int a, int b)
        {            
            if (!left && !right) return tracked;
            if (a<=begin && end<=b) return tracked;            
            int mid = (end-begin)/2+begin;
            bool leftTracked, rightTracked;
            if (a<mid)
                leftTracked = left->getTracking(a,b);
            else
                leftTracked = true;
            if (b>mid)
                rightTracked = right->getTracking(a,b);
            else
                rightTracked = true;
            return leftTracked && rightTracked;                
        }
        
    };
    
    
    
public:
    
    SegTree root = SegTree(0,1e9,false);
    
    RangeModule() 
    {
    }
    
    void addRange(int left, int right) 
    {
        root.setTracking(left,right,true);
    }
    
    bool queryRange(int left, int right) 
    {        
        return root.getTracking(left,right);
    }
    
    void removeRange(int left, int right) 
    {
        root.setTracking(left,right,false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
