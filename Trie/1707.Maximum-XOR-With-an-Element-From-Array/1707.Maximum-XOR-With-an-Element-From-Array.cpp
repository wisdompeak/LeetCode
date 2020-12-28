class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[2];
    };
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {        
        int n = queries.size();
        for (int i=0; i<queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);
        sort(nums.begin(), nums.end());

        vector<int>rets(n);
        TrieNode* root = new TrieNode();        
        int i = 0;
        for (auto q: queries)
        {
            while (i<nums.size() && nums[i]<=q[1])
            {
                TrieNode* node = root;
                for (int k=31; k>=0; k--)
                {
                    if (node->next[(nums[i]>>k)&1]==NULL)
                        node->next[(nums[i]>>k)&1] = new TrieNode();
                    node = node->next[(nums[i]>>k)&1];
                }
                i++;
            }
            
            if (i==0)
            {
                rets[q[2]]=-1;
                continue;
            }
                        
            TrieNode* node = root;
            int ret = 0;
            for (int k=31; k>=0; k--)
            {
                if (node->next[1-((q[0]>>k)&1)] != NULL)
                {
                    node = node->next[1-((q[0]>>k)&1)];
                    ret = ret*2 + 1;
                }                    
                else
                {
                    node = node->next[((q[0]>>k)&1)];
                    ret = ret*2 + 0;
                }
            }
            rets[q[2]] = ret;            
        }
        return rets;        
    }
};
