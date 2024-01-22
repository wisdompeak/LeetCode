class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    int info;  // the maximum value of the range
    bool tag; 
        
    SegTreeNode(int a, int b, int val)  // init for range [a,b] with val
    {                 
        tag = 0;
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
            info = max(left->info, right->info);  // check with your own logic
        }        
    }    
    
    SegTreeNode(int a, int b, vector<int>& val)  // init for range [a,b] with the same-size array val
    {                 
        tag = 0;
        info = 0;
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
            left->info = info;
            right->info = info;
            left->tag = 1;
            right->tag = 1;
            tag = 0;
        }        
    } 
    
    void updateRange(int a, int b, int val)     // set range [a,b] with val
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info = val;
            tag = 1;
            return;
        }

        if (left)
        {
            pushDown();        
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = max(left->info, right->info);  // write your own logic            
        }        
    }
    
    int queryRange(int a, int b)     // query the maximum value within range [a,b]
    {
        if (b < start || a > end )
        {
            return INT_MIN/2;  // check with your own logic
        }
        if (a <= start && end <=b)
        {
            return info;  // check with your own logic
        }          
        
        if (left)
        {
            pushDown();     
            int ret = max(left->queryRange(a, b), right->queryRange(a, b));        
            info = max(left->info, right->info);    // check with your own logic
            return ret;
        }
        
        return info;   // should not reach here
    }  

};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) 
    {
        set<int>Set(prices.begin(), prices.end());
        unordered_map<int,int>Map;
        int m = 0;
        for (int x: Set)
        {
            Map[x] = m;
            m++;
        }
                
        SegTreeNode* root1 = new SegTreeNode(0, m-1, -1);  // Set the leaf nodes with initVals.
        SegTreeNode* root2 = new SegTreeNode(0, m-1, -1);  // Set the leaf nodes with initVals.

        int n = prices.size();
        vector<int>left(n, -1);
        for (int i=0; i<n; i++)
        {
            left[i] = root1->queryRange(0, Map[prices[i]]-1);
            if (profits[i] > root1->queryRange(Map[prices[i]], Map[prices[i]]))
                root1->updateRange(Map[prices[i]], Map[prices[i]], profits[i]); // set the range [start, end] with val 
        }

        vector<int>right(n, -1);
        for (int i=n-1; i>=0; i--)
        {
            right[i] = root2->queryRange(Map[prices[i]]+1, m-1);
            if (profits[i] > root2->queryRange(Map[prices[i]], Map[prices[i]]))
                root2->updateRange(Map[prices[i]], Map[prices[i]], profits[i]); // set the range [start, end] with val 
        }

        int ret = -1;
        for (int i=0; i<n; i++)
        {
            if (left[i]!=-1 && right[i]!=-1)
                ret = max(ret, left[i]+profits[i]+right[i]);
        }
        return ret;
    }
};
