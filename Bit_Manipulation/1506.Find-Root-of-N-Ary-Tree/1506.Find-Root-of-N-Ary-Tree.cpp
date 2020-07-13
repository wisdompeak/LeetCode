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
public:
    Node* findRoot(vector<Node*> tree) 
    {
        int ret = 0;
        for (auto cur: tree)
        {
            ret ^= cur->val;
            for (auto next: cur->children)
                ret ^= next->val;
        }
        
        for (auto cur: tree)
        {
            if (cur->val == ret)
                return cur;
        }
        
        return NULL;
        
    }
};
