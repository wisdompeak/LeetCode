class Solution {
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;       
        int tag;
        SegTreeNode(int a, int b):start(a),end(b),info(0),tag(0),left(NULL),right(NULL){}
    };
    
    void init(SegTreeNode* node, int a, int b)  // init for range [a,b]
    {                        
        if (a==b)
        {
            node->info = 0;
            return;
        }
        int mid = (a+b)/2;
        if (node->left==NULL)
        {
            node->left = new SegTreeNode(a, mid);
            node->right = new SegTreeNode(mid+1, b);
        }
        init(node->left, a, mid);
        init(node->right, mid+1, b);
                
        node->info = 0;  // write your own logic
    }
    
    void updateRange(SegTreeNode* node, int a, int b, int val)
    {        
        if (b < node->start || a > node->end ) 
            return;
        if (node->start == node->end)
        {
            node->info = max(node->info, val);
            return;
        }        
        if (a <= node->start && node->end <=b && val >= node->info)
        {
            // write your own logic            
            node->info = val;    
            node->tag = 1;   
            return;
        }
        
        pushDown(node);        
        node->info = max(node->info, val);
        
        updateRange(node->left, a, b, val);
        updateRange(node->right, a, b, val);                
    }
    
   
    void pushDown(SegTreeNode* node)
    {
        if (node->tag!=0)
        {
            node->left->info = node->info;
            node->right->info = node->info;
            node->left->tag = 1;
            node->right->tag = 1;
            node->tag = 0;
        }        
    }    
    
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
        SegTreeNode* root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);
        
        sort(buildings.begin(), buildings.end(), [](vector<int>&a, vector<int>&b){return a[2]<b[2];});
        
        for (auto & building: buildings)
        {
            updateRange(root, pos2idx[building[0]], pos2idx[building[1]]-1, building[2]); 
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
