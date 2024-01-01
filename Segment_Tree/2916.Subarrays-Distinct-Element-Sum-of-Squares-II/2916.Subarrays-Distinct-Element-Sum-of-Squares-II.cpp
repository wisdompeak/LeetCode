using LL = long long;
LL M = 1e9+7;
class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;    
    LL info;  // the sum value over the range
    LL delta;
    bool tag; 
        
    SegTreeNode(int a, int b, int val)  // init for range [a,b] with val
    {                 
        tag = 0;
        delta = 0;
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
        tag = 0;
        delta = 0;
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
        if (tag==1 && left)
        {
            left->info += delta * (left->end - left->start + 1);            
            left->delta += delta;
            right->info += delta * (right->end - right->start + 1);
            right->delta += delta;
            left->tag = 1;
            right->tag = 1;
            tag = 0;
            delta = 0;
        }        
    } 
    
    void updateRangeBy(int a, int b, int val)     // increase range [a,b] by val
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info += val * (end-start+1);
            delta += val;
            tag = 1;
            return;
        }

        if (left)
        {            
            pushDown();
            left->updateRangeBy(a, b, val+delta);
            right->updateRangeBy(a, b, val+delta);
            delta = 0;
            tag = 0;
            info = left->info + right->info;  // write your own logic            
        }        
    }
    
    LL queryRange(int a, int b)     // query the sum within range [a,b]
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
    int sumCounts(vector<int>& nums) 
    {
        unordered_map<int,int>Map;
        int n = nums.size();
        vector<int>prev(n, -1);
        for (int i=0; i<n; i++)
        {
            if (Map.find(nums[i])!=Map.end())
                prev[i] = Map[nums[i]];
            Map[nums[i]] = i;
        }

        SegTreeNode* root = new SegTreeNode(0, n-1, 0);

        vector<LL>dp(n);
        for (int i=0; i<n; i++)
        {
            int j = prev[i];
            dp[i] = (i==0?0:dp[i-1]);            
            dp[i] += 2*root->queryRange(j+1, i-1) + i-1-j;            
            dp[i] += 1;
            dp[i] %= M;
            root->updateRangeBy(j+1, i, 1);            
        }

        LL ret = 0;
        for (int i=0; i<n; i++)
            ret = (ret+dp[i])%M;        

        return ret;
    }
};
