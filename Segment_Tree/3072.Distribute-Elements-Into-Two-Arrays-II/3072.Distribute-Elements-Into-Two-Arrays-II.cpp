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
    vector<int> resultArray(vector<int>& nums) 
    {
        set<int>Set(nums.begin(), nums.end());
        int idx = 0;
        unordered_map<int,int>Map;
        for (int x: Set)
        {
            Map[x] = idx;
            idx++;
        }
        int n = Set.size();
                    
        SegTreeNode* root1 = new SegTreeNode(0, n-1, 0); 
        int k = Map[nums[0]];
        root1->updateRangeBy(k, k , 1);
            
        SegTreeNode* root2 = new SegTreeNode(0, n-1, 0); 
        k = Map[nums[1]];
        root2->updateRangeBy(k, k , 1);
        
        vector<int>arr1({nums[0]});
        vector<int>arr2({nums[1]});
        for (int i=2; i<nums.size(); i++)
        {
            int k = Map[nums[i]];
            int x = root1->queryRange(k+1, n-1);
            int y = root2->queryRange(k+1, n-1);
            if (x>y)
            {
                arr1.push_back(nums[i]);
                root1->updateRangeBy(k, k, 1);
            }
            else if (x<y)
            {
                arr2.push_back(nums[i]);
                root2->updateRangeBy(k, k, 1);
            }
            else
            {
                if (arr1.size() <= arr2.size())
                {
                    arr1.push_back(nums[i]);
                    root1->updateRangeBy(k, k, 1);
                }
                else
                {
                    arr2.push_back(nums[i]);
                    root2->updateRangeBy(k, k, 1);
                }
            }
        }
        
        vector<int>rets;
        for (int x: arr1) rets.push_back(x);
        for (int x: arr2) rets.push_back(x);
        return rets;
    }
};
