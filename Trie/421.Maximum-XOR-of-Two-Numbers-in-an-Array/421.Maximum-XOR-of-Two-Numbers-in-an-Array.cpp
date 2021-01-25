class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[2];
    };
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        TrieNode* root = new TrieNode();
        for (auto num: nums)
        {
            TrieNode* node = root;
            for (int k=31; k>=0; k--)
            {
                if (node->next[(num>>k)&1]==NULL)
                    node->next[(num>>k)&1] = new TrieNode();
                node = node->next[(num>>k)&1];
            }
        }

        int ret = 0;
        for (auto num: nums)
        {
            TrieNode* node = root;
            int ans = 0;
            for (int k=31; k>=0; k--)
            {
                if (node->next[1 - (num>>k)&1]!=NULL)
                {
                    ans = ans*2+1;
                    node = node->next[1 - (num>>k)&1];
                }                    
                else
                {
                    ans = ans*2+0;
                    node = node->next[(num>>k)&1];
                }
            }
            ret = max(ret, ans);
        }
        return ret;
    }
};
