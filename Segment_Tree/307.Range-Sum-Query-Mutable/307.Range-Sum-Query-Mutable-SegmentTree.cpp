class NumArray {
    
    class SegTree
    {
        public:
        int status, begin, end;
        SegTree* left;
        SegTree* right;
        SegTree(int a, int b, int T)
        {
            begin = a;
            end = b;
            status = T;
            left = NULL;
            right = NULL;
        }
        
        int buildTree(int a, int b, vector<int>&nums)
        {                       
            if (b==a+1)            
                return status = nums[a];            
            if (a>=end || b<=begin)
                return status = 0;
            else if (b!=a+1)
            {
                int mid = (end-begin)/2+begin;
                left = new SegTree(a,mid,0);
                right = new SegTree(mid,b,0);
                left->buildTree(a,mid,nums);
                right->buildTree(mid,b,nums);                
                return status = left->status+right->status;
            }
        }
                        
        int setStatus(int a, int val)
        {
            if (begin==a && end==a+1)            
                return status = val;
            
            int mid = (end-begin)/2+begin;
            int leftStatus,rightStatus;
            if (a<mid)
                leftStatus = left->setStatus(a,val);
            else
                leftStatus = left->status;
            if (a>=mid)
                rightStatus = right->setStatus(a,val);
            else 
                rightStatus = right->status;
            
            return status = leftStatus+rightStatus;            
        }
        
        int getStatus(int a, int b)
        {
            if (a<=begin && end<=b)            
                return status;            
                
            if (a>=end || b<=begin)
                return 0;
            
            int mid = (end-begin)/2+begin;
            int leftStatus,rightStatus;
            if (a<mid)
                leftStatus = left->getStatus(a,b);
            else
                leftStatus = 0;
            if (b>mid)
                rightStatus = right->getStatus(a,b);
            else 
                rightStatus = 0;
            
            return leftStatus+rightStatus;  
        }
    };
    
    
public:
    SegTree* root;
        
    NumArray(vector<int> nums) 
    {
        root = new SegTree(0,nums.size(),0);        
        root->buildTree(0,nums.size(),nums);
    }
    
    void update(int i, int val) 
    {
        root->setStatus(i,val);
    }
    
    int sumRange(int i, int j) 
    {
        return root->getStatus(i,j+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
