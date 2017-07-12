class Solution {
public:
    class TrieNode
    {
        public:
         TrieNode* next[2];
         TrieNode()
         {
             next[0]=NULL;
             next[1]=NULL;
         }
    };
    
    TrieNode* buildTree(vector<int>nums)
    {
        TrieNode* root=new TrieNode();
        TrieNode* current;
        for (int i=0; i<nums.size(); i++)
        {
            current = root;
            for (int j=31; j>=0; j--)
            {
                int bit = ((nums[i]>>j)&1);
                if (current->next[bit]==NULL)
                    current->next[bit]=new TrieNode();
                current=current->next[bit];
            }
        }
        return root;
    }
    
    int oppositePath(TrieNode* root, int num)
    {
        TrieNode* node =root;
        int result=0;
        for (int i=31; i>=0; i--)
        {
            int bit= (num>>i)&1;
            if (node->next[1-bit]!=NULL)
            {
                node = node->next[1-bit];
                result += (1-bit)<<i;
            }
            else
            {
                node = node->next[bit];
                result += (bit)<<i;
            }
        }
        return result^num;
    }
    
    int findMaximumXOR(vector<int>& nums) 
    {
        TrieNode* root=buildTree(nums);
        int result=0;
        for (int i=0; i<nums.size(); i++)
        {
            result = max(result, oppositePath(root,nums[i]));
        }
        return result;
    }
};
