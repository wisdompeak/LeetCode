class MajorityChecker {
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info, freqDiff;        
        SegTreeNode(int a, int b):start(a),end(b),info(0),freqDiff(0),left(NULL),right(NULL){}
    };
    
    void init(SegTreeNode* node, int a, int b)  // init for range [a,b]
    {                        
        if (a==b)
        {
            node->info = arr[a];
            node->freqDiff = 1;
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
                
        if (node->left->info == node->right->info)
        {
            node->info = node->left->info;
            node->freqDiff = node->left->freqDiff + node->right->freqDiff;
        }
        else
        {
            if (node->left->freqDiff >= node->right->freqDiff)
            {
                node->info = node->left->info;
                node->freqDiff = node->left->freqDiff - node->right->freqDiff;
            }
            else
            {
                node->info = node->right->info;
                node->freqDiff = node->right->freqDiff - node->left->freqDiff;
            }
        }            
    }
    
    pair<int,int> queryRange(SegTreeNode* node, int a, int b)
    {
        if (b < node->start || a > node->end )
        {
            return {0,0};
        }
        if (a <= node->start && b>=node->end)
        {
            return {node->info, node->freqDiff};
        }        
        
        auto L = queryRange(node->left, a, b);
        auto R = queryRange(node->right, a, b);
        if (L.first==R.first)
            return {L.first, L.second+R.second};
        else
        {
            if (L.second>=R.second)
                return {L.first, L.second-R.second};
            else
                return {R.first, R.second-L.second};
        }
    }        
    
    SegTreeNode* root;
    vector<int> arr;
    unordered_map<int,vector<int>>Map;
    
public:
    MajorityChecker(vector<int>& arr) 
    {
        this->arr = arr;
        int n = arr.size();
        root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);
                
        for (int i=0; i<arr.size(); i++)
            Map[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) 
    {
        auto [val, freqDiff] = queryRange(root, left, right);
        
        auto pos1 = lower_bound(Map[val].begin(), Map[val].end(), left);
        auto pos2 = upper_bound(Map[val].begin(), Map[val].end(), right);
        int count = pos2-pos1;
        if (count >= threshold)
            return val;
        else
            return -1;        
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
