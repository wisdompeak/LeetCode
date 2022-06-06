// 支持动态开点

class SegTree
{
    public:
    int start,end,status;
    SegTree* left;
    SegTree* right;
    SegTree(int a, int b, int s):start(a),end(b),status(s),left(NULL),right(NULL){}

    void remove(SegTree* &node)
    {
        if (node==NULL) return;
        remove(node->left);
        remove(node->right);
        delete node;
        node = NULL;
        return;            
    }

    void setStatus(int a, int b, int s)
    {
        if (a>=end || b<=start)
            return;
        if (a<=start && b>=end && s>=status)
        {
            remove(left);
            remove(right);
            status = s;
            return;
        }
        if (a<=start && b>=end && s<status && left==NULL)
            return;
        if (left==NULL)
        {
            int mid = start+(end-start)/2;
            left = new SegTree(start,mid,status);
            right = new SegTree(mid,end,status);
        }
        left->setStatus(a,b,s);
        right->setStatus(a,b,s);
        status = max(left->status,right->status);            
    }
};

class Solution {
public:
    vector<vector<int>>results;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        if (buildings.size()==0) return {};
        
        SegTree* root = new SegTree(0,INT_MAX,0);
        for (auto q:buildings)
            root->setStatus(q[0],q[1],q[2]);
        
        DFS(root);
        if (results.back()[1]!=0) results.push_back({INT_MAX,0});
        
        vector<vector<int>>filteredResults;
        for (auto p: results)
        {
            if (filteredResults.size()!=0 && p[1]==filteredResults.back()[1])
                continue;
            filteredResults.push_back({p[0],p[1]});
        }
        if (filteredResults.size()!=0 && filteredResults[0][1]==0) filteredResults.erase(filteredResults.begin());
        return filteredResults;
    }
    
    void DFS(SegTree* node)
    {        
        if (node->left==NULL)
            results.push_back({node->start,node->status});
        else
        {
            DFS(node->left);
            DFS(node->right);
        }
    }
};
