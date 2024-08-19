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
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) 
    {
        int n = s.size();
        vector<int>end(n);
        int j = 0;
        int count0=0, count1=0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (count0+(s[j]=='0')<=k || count1+(s[j]=='1')<=k))
            {       
                count0+= (s[j]=='0');
                count1+= (s[j]=='1');                
                j++;                
            }
            end[i]=j-1;
            count0 -= (s[i]=='0');
            count1 -= (s[i]=='1');
        }
        
        for (int i=0; i<queries.size(); i++)
            queries[i].push_back(i);
        
        sort(queries.rbegin(), queries.rend());
        
        vector<LL>rets(queries.size());
        SegTreeNode* root = new SegTreeNode(0, n-1, 0); 
        
        int i = n-1;
        for (auto q: queries)
        {
            int a = q[0], b = q[1], idx=q[2];
            while (i>=a)
            {
                root->updateRangeBy(i, end[i], 1);
                i--;
            }
            rets[idx] = root->queryRange(a,b);            
        }
        
        return rets;
    }
};
