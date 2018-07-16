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
            if (a<=begin && end<=b)
            {
                remove(left);
                remove(right);
                return tracked = tracking;                
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
            if (!left && !right) return tracked;
            if (a<=begin && end<=b) return tracked;            
            int mid = (end-begin)/2+begin;
            int leftTracked, rightTracked;
            if (a<mid)
                leftTracked = left->getTracking(a,b);
            else
                leftTracked = 0;
            if (b>mid)
                rightTracked = right->getTracking(a,b);
            else
                rightTracked = 0;
            return max(leftTracked, rightTracked);                
        }
        
    };
    
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) 
    {
        SegTree root = SegTree(0,1e9,0);
        int curMaxH = 0;
        vector<int>results;
        for (int i=0; i<positions.size(); i++)
        {
            int maxH;
            maxH = root.getTracking(positions[i].first,positions[i].first+positions[i].second);
            root.setTracking(positions[i].first,positions[i].first+positions[i].second, positions[i].second+maxH);
            curMaxH = max(curMaxH, positions[i].second+maxH);
            results.push_back(curMaxH);
        }
        return results;
    }
};
