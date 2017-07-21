/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if (node==NULL) return NULL;
        
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>Map;
        queue<UndirectedGraphNode*>q;
        q.push(node);
        Map[node] = new UndirectedGraphNode(node->label);
        
        while (!q.empty())
        {
            UndirectedGraphNode* root = q.front();
            q.pop();
            for (int i=0; i<root->neighbors.size(); i++)
            {
                if (Map.find(root->neighbors[i])==Map.end())
                {
                    UndirectedGraphNode* temp = new UndirectedGraphNode(root->neighbors[i]->label);
                    Map[root->neighbors[i]] = temp;
                    Map[root]->neighbors.push_back(temp);
                    q.push(root->neighbors[i]);
                }
                else
                {
                    Map[root]->neighbors.push_back(Map[root->neighbors[i]]);
                }
            }
            
        }        
        return Map[node];
    }
};
