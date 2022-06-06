// 线段树大小在初始化时固定。支持Lazy Tag（延迟标记）

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
            return INT_MIN;  // check with your own logic
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
    vector<int> fallingSquares(vector<vector<int>>& positions) 
    {
        set<int>Set;
        for (auto & rect: positions)
        {
            Set.insert(rect[0]);
            Set.insert(rect[0]+rect[1]);
        }
        unordered_map<int,int>pos2idx;
        int idx = 0;
        for (auto x: Set)
        {
            pos2idx[x] = idx;
            idx++;
        }
        int n = pos2idx.size();
        
        SegTreeNode* root = new SegTreeNode(0, n-1, 0);
        
        int maxH = 0;
        vector<int>rets;
        for (auto & rect: positions)
        {
            int a = pos2idx[rect[0]];
            int b = pos2idx[rect[0]+rect[1]];
            int h = root->queryRange(a, b-1);  // [a,b)
            root->updateRange(a, b-1, h + rect[1]);
            maxH = max(maxH, h + rect[1]);
            rets.push_back(maxH);
        }
        return rets;        
    }
};
