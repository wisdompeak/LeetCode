/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node*,Node*>Map;
public:
    Node* cloneGraph(Node* oldNode) 
    {
        if (Map.find(oldNode)!=Map.end())
            return Map[oldNode];
            
        Node* newNode = new Node(oldNode->val);
        Map[oldNode] = newNode;
        
        for (int i=0; i<oldNode->neighbors.size(); i++)
        {
            newNode->neighbors.push_back(cloneGraph(oldNode->neighbors[i]));
        }
        
        return newNode;
    }
    
};
