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
    bool isDirectChild(Node* q, Node* p)
    {
        for (auto x: q->children)
        {
            if (x==p) return true;
        }
        return false;
    }
    
    Node* findParent(Node* root, Node* p)
    {
        for (auto x:root->children)
            if (x==p) return root;
        
        for (auto x:root->children)
        {
            Node* temp = findParent(x,p);
            if (temp!=NULL) return temp;                
        }            
        return NULL;
    }
    
    // Find child under parent, and replace it with node
    void disconnectOrReplace(Node* parent, Node* child, Node* node)
    {
        for (int i=0; i<parent->children.size(); i++)
        {
            if (parent->children[i]==child)
            {
                if (node==NULL)
                    parent->children.erase(parent->children.begin()+i);
                else
                    parent->children[i] = node;
                return;
            }                
        }
    }
    
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) 
    {
        if (isDirectChild(q,p))
            return root;
        
        Node* parentOfp = findParent(q,p);
        Node* parentOfq = findParent(p,q);
        
        if (p==root)
        {
            disconnectOrReplace(parentOfq, q, NULL);
            q->children.push_back(p);
            return q;
        }   
        else if (parentOfp!=NULL)  // p is in the subtree of q
        {
            disconnectOrReplace(parentOfp, p, NULL);
            q->children.push_back(p);
            return root;
        } 
        else if (parentOfq!=NULL)    // q is in the subtree of p
        {
            disconnectOrReplace(parentOfq, q, NULL);
            Node* parentOfp = findParent(root,p);            
            disconnectOrReplace(parentOfp, p, q);
            q->children.push_back(p);
            return root;        
        }        
        else  // p and q are in different subtrees
        {
            Node* parentOfp = findParent(root,p);
            disconnectOrReplace(parentOfp, p, NULL);
            q->children.push_back(p);
            return root;        
        }        
    }
};
