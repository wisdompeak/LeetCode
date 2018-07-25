class Solution {
    class SegNode
    {
        public:
        
        int begin, end, status;
        SegNode* left;
        SegNode* right;
        SegNode(int a, int b, int s)
        {
            begin = a;
            end = b;
            status = s;
            left = NULL;
            right = NULL;
        }
        
        void remove(SegNode* & node)
        {
            if (node==NULL) return;
            remove(node->left);
            remove(node->right);
            delete node;
            node=NULL;
        }
        
        int setStatus(int a, int b, int s)
        {
            if (b<=begin || a>=end)
            {
                return status;
            }
            if (a<=begin && end<=b && left==NULL)
            {                
                status += s;
                return status;
            }
            int mid = (end-begin)/2+begin;
            if (left==NULL)
            {              
                left = new SegNode(begin,mid,status);
                right = new SegNode(mid,end,status);
            }
            int leftStatus = left->setStatus(a,b,s);
            int rightStatus = right->setStatus(a,b,s);
            return max(leftStatus,rightStatus);
        }
    };
    
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        SegNode* root = new SegNode(0,length,0);
        
        for (int i=0; i<updates.size(); i++)
            root->setStatus(updates[i][0],updates[i][1]+1,updates[i][2]);
        
        vector<int>results(length);
        DFS(root,results);
        return results;
    }
    
    void DFS(SegNode* node, vector<int>& results)
    {
        if (node==NULL)
            return;
        if (node->left!=NULL)
        {
            DFS(node->left,results);
            DFS(node->right,results);
            return;
        }
        for (int i=node->begin; i<node->end; i++)
            results[i] = node->status;
    }
};
