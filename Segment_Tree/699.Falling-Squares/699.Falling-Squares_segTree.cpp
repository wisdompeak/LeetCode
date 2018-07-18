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
            if (a<=begin && end<=b)            // 2. [a,b]包括了整个区间，将该区间抹平
            {
                remove(left);
                remove(right);
                return status = s;
            }         
            if (!left)                         // 3. [a,b]与该区间相交，需考虑其子树
            {
                int mid = (end-begin)/2+begin;
                left = new SegTree(begin,mid,status);
                right = new SegTree(mid,end,status);
            }            
            int leftStatus = left->setStatus(a,b,s);
            int rightStatus = right->setStatus(a,b,s);
            return status = max(leftStatus,rightStatus);
        }
                
        int getStatus(int a, int b)
        {
            if (begin>=b || end<=a)            // 1. [a,b]与这个区间不相交，返回一个不影响结果的状态
                return 0;            
            if (a<=begin && end<=b)            // 2. [a,b]包括了整个区间，返回该区间的状态
                return status;                        
            if (!left)                         // 3. [a,b]与该区间相交，但又没有子树，返回整个区间状态
                return status;
            int mid = (end-begin)/2+begin;      // 4. [a,b]与该区间相交，需要考虑其子树
            int leftStatus = left->getStatus(a,b);
            int rightStatus = right->getStatus(a,b);
            return max(leftStatus,rightStatus);            
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
            maxH = root.getStatus(positions[i].first,positions[i].first+positions[i].second);
            root.setStatus(positions[i].first,positions[i].first+positions[i].second, positions[i].second+maxH);
            curMaxH = max(curMaxH, positions[i].second+maxH);
            results.push_back(curMaxH);
        }
        return results;
    }
};
