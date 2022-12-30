using LL = long long;
class Solution {
    map<pair<LL,LL>, int>Map;
public:
    long long fixedRatio(string s, int num1, int num2) 
    {
        Map[{0,0}] = 1;
        LL a = 0, b = 0;
        LL ret = 0;
        for (auto ch: s)
        {
            if (ch=='0') a++;
            else b++;

            LL k = min(a/num1, b/num2);
            LL x = a-k*num1, y = b-k*num2;

            if (Map.find({x,y})!=Map.end())            
                ret += Map[{x,y}];            

            Map[{x,y}] += 1;                
        }

        return ret;
    }
};
