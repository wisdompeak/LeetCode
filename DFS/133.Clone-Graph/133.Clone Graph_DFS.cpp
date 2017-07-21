/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>Map;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if (node==NULL) return NULL;
        
        UndirectedGraphNode* root=new UndirectedGraphNode(node->label);
        Map[node]=root;
        for (int i=0; i<node->neighbors.size(); i++)
        {
            if (Map.find(node->neighbors[i])==Map.end())
            {
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
            else
            {
                root->neighbors.push_back(Map[node->neighbors[i]]);
            }
        }
        
        return root;
    }
};
