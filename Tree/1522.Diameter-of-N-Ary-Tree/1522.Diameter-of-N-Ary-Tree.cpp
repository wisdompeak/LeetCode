/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int ret = 0;
public:
    int diameter(Node* root) 
    {
        DFS(root);        
        return ret-1;
    }
    
    int DFS(Node* node)
    {
        if (node==NULL) return 0;
        vector<int>depths;        
        for (auto child: node->children)
            depths.push_back(DFS(child));
        sort(depths.rbegin(), depths.rend());
        
        int n = depths.size();
        if (n>=2)
        {
            ret = max(ret, depths[0]+depths[1]+1);
            return depths[0]+1;                
        }            
        else if (n==1)
        {
            ret = max(ret, depths[0]+1);
            return depths[0]+1;       
        }            
        else
        {
            ret = max(ret, 1);
            return 1;
        }
            
    }
};
