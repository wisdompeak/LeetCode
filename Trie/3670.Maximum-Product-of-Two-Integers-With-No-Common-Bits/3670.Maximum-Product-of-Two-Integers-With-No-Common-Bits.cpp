class TrieNode {
    public:
        TrieNode* next[2];        
    TrieNode()
    {
        for (int i=0; i<2; i++)
            next[i]=NULL;        
    }
};

class Solution {
    TrieNode* root;    
public:
    void add(int x) {        
        TrieNode* node = root;
        for (int i=0; i<31; i++) {
            int b = ((x>>(30-i))&1);
            if (!node->next[b])
                node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }    

    int dfs(TrieNode* node, int i, int x) {        
        if (node==NULL) {
            return -1;
        }
        if (i==31) return 0;
        
        int b = ((x>>(30-i))&1);        
        if (b==1) {
            int ans = dfs(node->next[0], i+1, x);
            if (ans!=-1) return ans;
            else return -1;
        }            
        else {
            int ans1 = dfs(node->next[1], i+1, x);            
            if (ans1!=-1) 
                return (1<<(30-i))+ans1;
            int ans2 = dfs(node->next[0], i+1, x);
            if (ans2!=-1)
                return ans2;
            return -1;
        }
    }
    
    long long maxProduct(vector<int>& nums) {
        root = new TrieNode();
        int n = nums.size();        

        long long ret = 0;
        for (int x: nums) {
            int ans = dfs(root, 0, x);     
            if (ans!=-1) ret = max(ret, (long long)x*ans);
            add(x);
        }

        return ret;
    }
};
