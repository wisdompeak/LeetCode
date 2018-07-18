class Solution {
    class SegTree
    {
        public:
        int begin, end, status;
        SegTree* left;
        SegTree* right;
        SegTree(int a, int b, int T)
        {
            begin = a;
            end = b;            
            status = T;
            left = NULL;
            right = NULL;
        }                
        
        void remove(SegTree* &node)
        {
            if (!node) return;
            remove(node->left);
            remove(node->right);
            delete node;
            node = NULL;
        }
        
        int setStatus(int a, int b, int s)
        {
            if (begin>=b || end<=a)            // 1. [a,b]与这个区间不相交，返回原先的状态
                return status;                        
            if (a<=begin && end<=b && status<=s)            // 2. [a,b]包括了整个区间，并且该区间的status<s,则将该区间抹平
            {
                remove(left);
                remove(right);
                return status = s;
            }         
            if (a<=begin && end<=b && status>s && !left)    // 3. [a,b]包括了整个区间，并且该区间的status>s,且无子树，则整体不更新
            {
                return status;
            }         
            if (!left)                         // 4. 其他情况，需考虑其子树
            {
                int mid = (end-begin)/2+begin;
                left = new SegTree(begin,mid,status);
                right = new SegTree(mid,end,status);
            }            
            int leftStatus = left->setStatus(a,b,s);
            int rightStatus = right->setStatus(a,b,s);
            return status = max(leftStatus,rightStatus);
        }
        
    };
    
public:
    vector<pair<int,int>>Set;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
    {
        if (buildings.size()==0)
            return {};
        
        SegTree root = SegTree(0,INT_MAX,0);
        for (int i=0; i<buildings.size(); i++)
            root.setStatus(buildings[i][0],buildings[i][1],buildings[i][2]);        
        
        SegTree* node = &root;
        DFS(node);
        
        if (Set.back().second!=0)
            Set.push_back({INT_MAX,0});
        int i = Set.size()-1;
        while (i>=0 && Set[i].second==0)
            i--;
        Set.resize(i+2);
        return Set;
    }
    
    void DFS(SegTree* node)
    {
        if (node==NULL) return;
        if (node->left!=NULL)
        {
            DFS(node->left);
            DFS(node->right);
        }
        else
        {
            if (Set.size()==0 && node->status==0)
                return;
            else if (Set.size()>0 && node->status==Set.back().second)
                return;
            else
                Set.push_back({node->begin,node->status});                
        }
    }
};
