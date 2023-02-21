using LL = long long;
class Solution {
    LL M = 1e9+7;
public:
    int numberOfUniqueGoodSubsequences(string binary) 
    {
        int one = 0, zero = 0;
        for (auto ch: binary)
        {
            if (ch=='0')
                zero = (one + zero) % M;
            else
                one = (one + zero + 1) % M;
        }
        return (one + zero + (binary.find("0")==-1? 0:1)) % M;
    }
};
