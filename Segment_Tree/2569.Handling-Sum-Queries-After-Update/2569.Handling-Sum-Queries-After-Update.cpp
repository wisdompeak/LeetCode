using LL = long long;
class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    LL info;  // the sum value over the range
    bool lazy_tag;   // if the child ranges are pending propagation
    LL lazy_val;     // how many flips needed to be propagated to child ranges.
        
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
            if (lazy_val % 2 == 1)
            {
                left->info = (left->end - left->start + 1) - left->info;
                right->info = (right->end - right->start + 1) - right->info;
                left->lazy_tag = 1; left->lazy_val += lazy_val;
                right->lazy_tag = 1; right->lazy_val += lazy_val;
            }              

            lazy_tag = 0;  lazy_val = 0;
        }        
    } 
    
    void updateRange(int a, int b)     // set range [a,b] with flips
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info = (end-start+1) - info;
            lazy_tag = 1;
            lazy_val += 1; 
            return;
        }

        if (left)
        {
            pushDown();                    
            left->updateRange(a, b);
            right->updateRange(a, b);
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
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) 
    {
        int n = nums1.size();
        SegTreeNode* root = new SegTreeNode(0, n-1, nums1);
        LL sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<LL>rets;
        for (auto & query: queries)
        {
            if (query[0]==1)
                root->updateRange(query[1], query[2]);
            else if (query[0]==2)
                sum += root->queryRange(0, n-1) * query[1];
            else
                rets.push_back(sum);
        }

        return rets;
    }
};
