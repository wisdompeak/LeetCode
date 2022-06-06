using LL = long long;
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
    
    void pushDown()
    {
        if (tag==1 && left)
        {
            left->delta += delta;
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
            delta += val;
            tag = 1;
            return;
        }

        if (left)
        {
            pushDown();        
            left->updateRangeBy(a, b, val);
            right->updateRangeBy(a, b, val);
            info = left->info + right->info;  // write your own logic            
        }        
    }
    
    LL queryRange(int a, int b)     // query the maximum value within range [a,b]
    {
        if (b < start || a > end )
        {
            return 0;  // check with your own logic
        }
        if (a <= start && end <=b)
        {
            return info + delta*(end-start+1);  // check with your own logic
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
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        SegTreeNode* root = new SegTreeNode(0, length-1, 0);
        
        for (auto update: updates)
        {
            root->updateRangeBy(update[0], update[1], update[2]);
        }
        
        vector<int>rets(length);
        for (int i=0; i<length; i++)
        {
            rets[i] = root->queryRange(i, i);
        }
            
        return rets;
    }
};

