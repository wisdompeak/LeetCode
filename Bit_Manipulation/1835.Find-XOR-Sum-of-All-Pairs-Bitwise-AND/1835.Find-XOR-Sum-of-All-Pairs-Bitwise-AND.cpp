class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int>ones(32);
        for (auto b: arr2)
        {
            for (int i=0; i<32; i++)
            {
                if ((b>>i)&1)
                    ones[i]++;
            }
        }
        
        int ret = 0;
        for (auto a: arr1)
        {
            int temp = 0;
            for (int i=0; i<32; i++)
            {
                if (((a>>i)&1)==0)
                    continue;
                temp += ((ones[i]%2)<<i);                    
            }
            ret ^= temp;
        }
        return ret;        
    }
};
