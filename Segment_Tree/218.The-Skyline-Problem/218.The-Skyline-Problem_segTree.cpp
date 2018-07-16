class Solution {
    class SegTree
    {
        public:
        int begin, end;
        SegTree* left;
        SegTree* right;
        int tracked;
        SegTree(int a, int b, int T)
        {
            begin = a;
            end = b;            
            tracked = T;
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
        
        int setTracking(int a, int b, int tracking)
        {            
            if (a<=begin && end<=b && tracking>tracked)
            {
                remove(left);
                remove(right);
                return tracked = tracking;                
            }
            if (a<=begin && end<=b && tracking<=tracked && left==NULL)
            {
                return tracked;
            }            
            int mid = (end-begin)/2+begin;
            if (!left)
            {
                left = new SegTree(begin,mid,tracked);
                right = new SegTree(mid,end,tracked);
            }
            int leftTracked, rightTracked;
            if (a<mid)            
                leftTracked = left->setTracking(a,b,tracking);
            else
                leftTracked = left->tracked;
            if (b>mid)
                rightTracked = right->setTracking(a,b,tracking);
            else
                rightTracked = right->tracked;
            return tracked = max(leftTracked, rightTracked);            
        }
        
        int getTracking(int a, int b)
        {   
            if (left == NULL) return tracked;
            if (a<=begin && end<=b) return tracked;
            int mid = (end-begin)/2+begin;
            int leftStatus, rightStatus;
            if (a<mid)
                leftStatus = left->getTracking(a,b);
            else
                leftStatus = 0;
            if (b>mid)
                rightStatus = right->getTracking(a,b);
            else
                rightStatus = 0;
            return max(leftStatus,rightStatus);
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
            root.setTracking(buildings[i][0],buildings[i][1],buildings[i][2]);        
        
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
            if (Set.size()==0 && node->tracked==0)
                return;
            else if (Set.size()>0 && node->tracked==Set.back().second)
                return;
            else
                Set.push_back({node->begin,node->tracked});                
        }
    }
};
