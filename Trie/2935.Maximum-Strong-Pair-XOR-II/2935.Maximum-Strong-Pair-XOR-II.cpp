class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[2];
        int count = 0;
        TrieNode(){
            for (int i=0; i<2; i++)
                next[i] = NULL;
        }
    };
    TrieNode* root;

public:
    int maximumStrongPairXor(vector<int>& nums) 
    {
        root = new TrieNode();

        sort(nums.begin(), nums.end());
        int j = 0;
        int ret = INT_MIN/2;
        for (int i=0; i<nums.size(); i++)
        {
            while (j<nums.size() && nums[j]<=2*nums[i])
            {
                add(nums[j]);
                j++;
            }                
            ret = max(ret, dfs(nums[i], root, 31));
            remove(nums[i]);
        }
        return ret;        
    }

    void add(int num)
    {
        TrieNode* node = root;
        for (int k=31; k>=0; k--)
        {
            int bit = ((num>>k)&1);
            if (node->next[bit]==NULL)
                node->next[bit] = new TrieNode();
            node = node->next[bit];
            node->count+=1;
        }
    }

    void remove(int num)
    {
        TrieNode* node = root;
        for (int k=31; k>=0; k--)
        {
            int bit = ((num>>k)&1);
            node = node->next[bit];
            node->count-=1;
        }
    }

    int dfs(int num, TrieNode* node, int k)
    {
        if (k==-1) return 0; 
        int bit = (num>>k)&1;
        if (bit == 0)
        {
            if (node->next[1] && node->next[1]->count > 0) 
                return dfs(num, node->next[1], k-1) + (1<<k);
            else if (node->next[0] && node->next[0]->count > 0) 
                return dfs(num, node->next[0], k-1);            
        }
        else
        {
            if (node->next[0] && node->next[0]->count > 0) 
                return dfs(num, node->next[0], k-1) + (1<<k);
            else if (node->next[1] && node->next[1]->count > 0) 
                return dfs(num, node->next[1], k-1);            
        }

        return INT_MIN/2;
    }
};
