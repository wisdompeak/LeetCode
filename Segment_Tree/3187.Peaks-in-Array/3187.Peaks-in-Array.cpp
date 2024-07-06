using LL = long long;
class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    LL info;  // the sum value over the range
    bool lazy_tag; 
    LL lazy_val;
        
    SegTreeNode(int a, int b, int val)  // init for range [a,b] with val
    {                 
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val;
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }    
    
    SegTreeNode(int a, int b, vector<int>& val)  // init for range [a,b] with the same-size array val
    {                 
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val[a];
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }    
    
    void pushDown()
    {
        if (lazy_tag==1 && left)
        {
            left->info = lazy_val * (left->end - left->start + 1);
            right->info = lazy_val * (right->end - right->start + 1);
            left->lazy_tag = 1; left->lazy_val = lazy_val;
            right->lazy_tag = 1; right->lazy_val = lazy_val;
            lazy_tag = 0;  lazy_val = 0;
        }        
    } 
    
    void updateRange(int a, int b, int val)     // set range [a,b] with val
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info = val * (end-start+1);
            lazy_tag = 1;
            lazy_val = val;
            return;
        }

        if (left)
        {
            pushDown();        
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = left->info + right->info;  // write your own logic            
        }        
    }
    
    LL queryRange(int a, int b)     // query the sum over range [a,b]
    {
        if (b < start || a > end )
        {
            return 0;  // check with your own logic
        }
        if (a <= start && end <=b)
        {
            return info;  // check with your own logic
        }          
        
        if (left)
        {
            pushDown();     
            LL ret = left->queryRange(a, b) + right->queryRange(a, b);        
            info = left->info + right->info;    // check with your own logic
            return ret;
        }
        
        return info;   // should not reach here
    }  
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int>peaks(n, 0);
        for (int i=1; i<n-1; i++)
        {
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1])
                peaks[i] = 1;
        }
        
        SegTreeNode* root = new SegTreeNode(0, n-1, peaks); 
        
        vector<int>rets;
        for (auto query: queries)
        {
            if (query[0]==1)
            {
                int a = query[1], b = query[2];                
                rets.push_back(root->queryRange(a+1, b-1));                
            }                
            else
            {
                int i = query[1];
                nums[i] = query[2];
                if (i>=1 && i<n-1) check(root, i, nums, peaks);
                if (i-1>=1 && i-1<n-1) check(root, i-1, nums, peaks);
                if (i+1>=1 && i+1<n-1) check(root, i+1, nums, peaks);                
            }                
        }
        
        return rets;      
    }

    void check(SegTreeNode* root, int i, vector<int>&nums, vector<int>&peaks)
    {
        int v = nums[i]>nums[i-1] && nums[i]>nums[i+1];
        if (v==peaks[i]) return;
        peaks[i] = v;
        root->updateRange(i,i,v);
    }
};
