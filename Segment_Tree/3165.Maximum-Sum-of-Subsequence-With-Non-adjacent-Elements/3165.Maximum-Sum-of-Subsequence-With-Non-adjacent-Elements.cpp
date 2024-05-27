using LL = long long;
LL M = 1e9+7;
class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    LL info00, info11, info10, info01;
        
    SegTreeNode(int a, int b, vector<int>& vals)  // init for range [a,b] with val
    {                 
        start = a, end = b;
        if (a==b)
        {
            info11 = vals[start], info01 = -1e18, info10 = -1e18, info00 = 0;
            return;
        }        
        int mid = (a+b)/2;

        left = new SegTreeNode(a, mid, vals);
        right = new SegTreeNode(mid+1, b, vals);            
        info11 = max({left->info10 + right->info01, left->info11 + right->info01, left->info10 + right->info11});
        info00 = max({left->info00 + right->info00, left->info01 + right->info00, left->info00 + right->info10});
        info10 = max({left->info10 + right->info00, left->info10 + right->info10, left->info11 + right->info00});
        info01 = max({left->info00 + right->info01, left->info01 + right->info01, left->info00 + right->info11});
    }
    
    void updateRange(int a, int val)     // set range [a,b] with val
    {        
        if (a < start || a > end ) // not covered by [a,b] at all
            return;        
        if (start==end)  // completely covered within [a,b]
        {
            info00 = 0;
            info11 = val;
            return;
        }

        left->updateRange(a, val);
        right->updateRange(a, val);
        info11 = max({left->info10 + right->info01, left->info11 + right->info01, left->info10 + right->info11});
        info00 = max({left->info00 + right->info00, left->info01 + right->info00, left->info00 + right->info10});
        info10 = max({left->info10 + right->info00, left->info10 + right->info10, left->info11 + right->info00});
        info01 = max({left->info00 + right->info01, left->info01 + right->info01, left->info00 + right->info11});
    }
};

    
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        SegTreeNode* root = new SegTreeNode(0, n-1, nums);

        LL ret = 0;
        for (auto q: queries)
        {
            root->updateRange(q[0], q[1]);
            ret += max({root->info00,root->info01,root->info10,root->info11});
            ret%=M;
        }
       return ret;
    }
};
