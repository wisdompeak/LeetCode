class Solution {
public:
    int getMinSwaps(string num, int k) 
    {
        auto num0 = num;
        for (int i=0; i<k; i++)
        {
            std::next_permutation(num.begin(), num.end());
        }
        
        int ret = 0;
        for (int i=0; i<num.size(); i++)
        {
            int count = 0;
            for (int j=0; j<num0.size(); j++)
            {
                if (num0[j]==num[i])
                {
                    num0[j] = '#';
                    break;
                }                    
                if (num0[j]=='#')
                    continue;
                count++;
            }
            ret += count;
        }
        return ret;
    }
};
