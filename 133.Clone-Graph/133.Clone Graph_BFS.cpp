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
        UndirectedGraphNode* head=new UndirectedGraphNode(node->label);
        Map[node]=head;
        
        queue<UndirectedGraphNode*>q;
        q.push(node);

        while (!q.empty())
        {
            UndirectedGraphNode* x=q.front();
            q.pop();

            for (int i=0; i<x->neighbors.size(); i++)
            {
                //cout<<i<<endl;
                
                if (Map.find(x->neighbors[i])==Map.end())
                {
                    UndirectedGraphNode* y = new UndirectedGraphNode(x->neighbors[i]->label);
                    Map[x->neighbors[i]] = y;
                    q.push(x->neighbors[i]);
                }
                Map[x]->neighbors.push_back(Map[x->neighbors[i]]);
            }
        }
        
        return head;
        
        
    }
};
