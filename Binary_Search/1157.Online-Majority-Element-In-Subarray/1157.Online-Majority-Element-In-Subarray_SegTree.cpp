class MajorityChecker {
    class SegTree
    {
        public:
        SegTree* left;
        SegTree* right;
        int val, count;
        int start,end;        
        SegTree(int a, int b):start(a),end(b),val(0),count(0),left(NULL),right(NULL){}        
    };
    vector<int>arr;
    unordered_map<int,vector<int>>Map;
public:
    SegTree* root;
    
    MajorityChecker(vector<int>& arr) 
    {        
        this->arr = arr;
        root = buildTree(0, arr.size()-1);        
        for (int i=0; i<arr.size(); i++)
            Map[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) 
    {
        int key = 0, val = 0;
        searchTreeMajority(root, left, right, key, val);
        if (key == 0) return -1;
        
        int pos1 = lower_bound(Map[key].begin(), Map[key].end(), left) - Map[key].begin();
        int pos2 = upper_bound(Map[key].begin(), Map[key].end(), right) - Map[key].begin() -1;
        
        if (pos2-pos1+1 >= threshold)
            return key;
        else
            return -1;        
    }
    
    SegTree* buildTree(int a, int b)
    {
        SegTree* node = new SegTree(a,b);
        
        if (a == b)
        {
            node->val = arr[a];
            node->count = 1;
            return node;
        }
        
        int mid = (a+b)/2;
        node->left = buildTree(a, mid);
        node->right = buildTree(mid+1, b);
        
        if (node->left->val==node->right->val)
        {
            node->val = node->left->val;
            node->count = node->left->count + node->right->count;
        }
        else if (node->left->count > node->right->count)
        {
            node->val = node->left->val;
            node->count = node->left->count - node->right->count;
        }
        else
        {
            node->val = node->right->val;
            node->count = node->right->count - node->left->count;
        }
        
        if (node->count==0)
            node->val = 0;
            
        return node;
    }
    
    
    bool searchTreeMajority(SegTree* node, int a, int b, int& key, int& count)
    {
        if (node==NULL || a>b)
            return false;
        
        if (node->start>b || node->end<a)
            return false;
        
        if (a<=node->start && node->end<=b)
        {
            key = node->val;
            count = node->count;
            return key!=0;
        }
        
        int key1, key2, count1, count2;
        int leftCheck = searchTreeMajority(node->left, a, b, key1, count1);
        int rightCheck = searchTreeMajority(node->right, a, b, key2, count2);
        
        if (!leftCheck && !rightCheck)
        {
            key = 0;
            count = 0;
        }
        else if (!leftCheck && rightCheck)
        {
            key = key2;
            count = count2;
        }
        else if (leftCheck && !rightCheck)
        {
            key = key1;
            count = count1;
        }
        else
        {
            if (key1==key2)
            {
                key = key1;
                count = count1+count2;
            }
            else if (count1==count2)
            {
                key = 0;
                count = 0;
            }
            else if (count1>count2)
            {
                key = key1;
                count = count1-count2;
            }
            else
            {
                key = key2;
                count = count2-count1;
            }                
        }
        
        return key!=0;
    }
    
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
