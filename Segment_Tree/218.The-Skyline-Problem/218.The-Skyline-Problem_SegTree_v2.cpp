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
    vector<pair<int,int>>height; // {idx, h}
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        set<int>Set;
        for (auto & building: buildings)
        {
            Set.insert(building[0]);
            Set.insert(building[1]);
        }
        int id = 0;
        unordered_map<int,int>pos2idx;
        unordered_map<int,int>idx2pos;
        for (auto x:Set)
        {
            pos2idx[x] = id;
            idx2pos[id] = x;
            id++;
        }
        
        int n = pos2idx.size();
        SegTreeNode* root = new SegTreeNode(0, n-1, 0);        
        
        sort(buildings.begin(), buildings.end(), [](vector<int>&a, vector<int>&b){return a[2]<b[2];});
        
        for (auto & building: buildings)
        {
            root->updateRange(pos2idx[building[0]], pos2idx[building[1]]-1, building[2]); 
        }
        
        DFS(root);
                
        vector<vector<int>>rets;
        for (int i=0; i<height.size(); i++)
        {
            auto [idx, h] = height[i];
            rets.push_back({idx2pos[idx], h});
            while (i+1 < height.size() && height[i+1].second == height[i].second)
                i++;
        }
        return rets;
    }
    
    void DFS(SegTreeNode* node)
    {
        if (node->start==node->end || node->tag==1)
        {
            height.push_back({node->start, node->info});
            return;
        }
        DFS(node->left);
        DFS(node->right);
    }
    
};
