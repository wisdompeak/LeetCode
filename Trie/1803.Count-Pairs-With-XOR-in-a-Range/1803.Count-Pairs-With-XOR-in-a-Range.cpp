class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[2];
        int cnt;
        TrieNode() 
        {
            for (int i=0; i<2; i++)
                next[i] = NULL;
            cnt=0; 
        }
    };
public:
    int countPairs(vector<int>& nums, int low, int high) 
    {
        return countSmallerPairs(nums, high+1) - countSmallerPairs(nums, low);
    }

    int countSmallerPairs(vector<int>&nums, int th)
    {
        TrieNode* root = new TrieNode();
        int count = 0;
        for (int num: nums)
        {
            count += countSmallerThan(root, num, th);
            insert(root, num);
        }
        return count;
    }

    int countSmallerThan(TrieNode* root, int num, int th)
    {
        auto node = root;
        int count = 0;
        for (int i=31; i>=0; i--)
        {
            int c = (th>>i)&1;
            int b = (num>>i)&1;
            int a = c ^ b;
            if (a == 1 && c == 1)
            {
                if (node->next[0]) count += node->next[0]->cnt;
                if (node->next[1]) node = node->next[1];
                else break;
            }
            else if (a==1 && c==0)
            {
                if (node->next[1]) node = node->next[1];
                else break;
            }
            else if (a==0 && c==1)
            {
                if (node->next[1]) count += node->next[1]->cnt;
                if (node->next[0]) node = node->next[0];
                else break;
            }
            else if (a==0 && c==0)
            {
                if (node->next[0]) node = node->next[0];
                else break;
            }
        }
        return count;
    }

    void insert(TrieNode* root, int num)
    {
        auto node = root;
        for (int i=31; i>=0; i--)
        {
            if ((num>>i)&1)
            {
                if (node->next[1]==NULL)
                    node->next[1] = new TrieNode();
                node->next[1]->cnt++;
                node = node->next[1];
            }
            else
            {
                if (node->next[0]==NULL)
                    node->next[0] = new TrieNode();
                node->next[0]->cnt++;
                node = node->next[0];
            }
        }
    }
};
