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
            info = max(left->info, right->info);  // check with your own logic
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
    vector<bool> getResults(vector<vector<int>>& queries) 
    {
        int n = min(50000, (int)queries.size()*3) + 5;
        SegTreeNode* root = new SegTreeNode(0, n, 0);

        set<int>Set;
        Set.insert(0);

        vector<bool>rets;

        for (auto q:queries)
        {
            if (q[0]==1)
            {
                int x = q[1];
                Set.insert(x);
                auto iter = Set.find(x);
                int a = *prev(iter);
                root->updateRange(x,x,x-a);

                if (next(iter)!=Set.end())
                {
                    int b = *next(iter);
                    root->updateRange(b,b,b-x);
                }
            }
            else
            {
                int x = q[1], sz = q[2];
                int len = root->queryRange(0, x);

                if (Set.find(x)==Set.end())
                {
                    auto iter = Set.lower_bound(x);
                    int  a = *prev(iter);
                    len = max(len, x-a);
                }
                rets.push_back(len >= sz);
            }
        }
        
        return rets;
    }
};
