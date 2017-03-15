/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>Map;
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if (node==NULL) return NULL;
        
        UndirectedGraphNode *root;
        
        if (Map.find(node)!=Map.end())
            return Map[node];
        else
        {
            root = new UndirectedGraphNode(node->label);
            Map[node] = root;
            
            for (int i=0; i<node->neighbors.size(); i++)
            {
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
            
            return root;
        }
        
            
    }
    
};
