class Solution {
public:
    int minSwaps(string s) 
    {
        int count=0;
        int unmatch = 0;
        for (auto ch: s)
        {
            if (ch=='[')
                count++;
            else
                count--;
            if (count < 0)
            {
                unmatch++;
                count = 0;
            }
        }
        return (unmatch+1)/2;
    }
};
