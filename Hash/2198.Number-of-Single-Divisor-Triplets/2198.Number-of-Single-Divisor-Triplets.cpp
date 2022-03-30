using LL = long long;
class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) 
    {
        unordered_map<int, int>Map;
        for (int i=0; i<nums.size(); i++)
            Map[nums[i]]++;

        LL ret = 0;
        for (int a=1; a<=100; a++)
            for (int b=a+1; b<=100; b++)
                for (int c=b+1; c<=100; c++)
                {                    
                    int  sum = a+b+c;
                    int count = (sum%a==0) + (sum%b==0) + (sum%c==0);
                    if (count != 1) continue;
                    ret += (LL)Map[a]*(LL)Map[b]*(LL)Map[c]*6;
                }
        
        for (int a=1; a<=100; a++)
            for (int b=1; b<=100; b++)
                {                    
                    if (b==a) continue;
                    int  sum = a+a+b;
                    int count = (sum%a==0) + (sum%a==0) + (sum%b==0);
                    if (count != 1) continue;
                    ret += (LL)Map[a]*((LL)Map[a]-1)/2*(LL)Map[b]*6;
                }
        
        return ret;
    }
};
