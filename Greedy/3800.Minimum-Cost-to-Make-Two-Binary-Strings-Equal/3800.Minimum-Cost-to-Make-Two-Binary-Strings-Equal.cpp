using ll = long long;
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();
        ll c01 = 0, c10 = 0;
        for (int i=0; i<n; i++) {
            if (s[i]=='0' && t[i]=='1') c01++;
            else if (s[i]=='1' && t[i]=='0') c10++;
        }

        ll ret = 0;

        ll pairs = min(c01, c10);
        ret += min(swapCost, 2*flipCost)*pairs;
        c10-=pairs;
        c01-=pairs;

        int count = max(c01, c10);
        pairs = count/2;
        ret += min(flipCost*2, crossCost+swapCost)*pairs;

        if (count%2==1) ret += flipCost;

        return ret;
    }
};
