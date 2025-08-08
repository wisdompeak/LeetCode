class TrieNode {
    public:
        TrieNode* next[2];        
        int count;
    TrieNode()
    {
        for (int i=0; i<2; i++)
            next[i]=NULL;        
        count = 0;
    }
};
class Solution {
    void add(int x) {        
        TrieNode* node = root;
        for (int i=0; i<31; i++) {
            int b = ((x>>(30-i))&1);
            if (!node->next[b])
                node->next[b] = new TrieNode();
            node = node->next[b];
            node->count += 1;
        }
    }
    TrieNode* root;
public:
    long long countXorSubarrays(vector<int>& nums, int k) {
        root = new TrieNode();
        int n = nums.size();
        
        long long ret = 0;
        int sum = 0;        
        add(sum);
        for (int i=0; i<n; i++) {
            sum^=nums[i];            
            TrieNode* node = root;
            int flag = 1;
            for (int j=0; j<31; j++) {
                int bitK = ((k>>(30-j))&1);
                int bitS = ((sum>>(30-j))&1);
                int b = bitK^bitS;
                if (bitK==0 && node->next[1-b]) {                    
                    ret += node->next[1-b]->count;
                }
                if (node->next[b]) 
                    node = node->next[b];
                else {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ret += node->count;

            add(sum);
        }

        return ret;
    }
};
