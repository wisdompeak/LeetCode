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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) 
    {        
        if (root==NULL) return "#";
        string ret = to_string(root->val) + ":" + to_string(root->children.size()) + ",";
        for (int i=0; i<root->children.size(); i++)
            ret += serialize(root->children[i]) + ",";
        ret.pop_back();
        return ret;        
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) 
    {
        if (data=="#") return NULL;
        vector<Node*>nodes;
        for (int i=0; i<data.size(); i++)
        {
            int j = i;
            while (j<data.size() && data[j]!=',')
                j++;
            string str = data.substr(i,j-i);
            int pos = str.find(":");
            Node* node = new Node(stoi(str.substr(0,pos)));
            node->children.resize(stoi(str.substr(pos+1)));                
            nodes.push_back(node);
            i = j;
        }

        return dfs(nodes, 0);   
    }
    
    Node* dfs(vector<Node*>&nodes, int cur)
    {
        int start = cur+1;
        for (int i=0; i<(nodes[cur]->children.size()); i++)
        {
            nodes[cur]->children[i] = dfs(nodes, start);
            start += getSize(nodes[cur]->children[i]);
        }
        return nodes[cur];
    }
    
    int getSize(Node* node)
    {
        if (node==NULL) return 0;
        int count = 1;
        for (int i=0; i<node->children.size(); i++)
            count += getSize(node->children[i]);
        return count;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
