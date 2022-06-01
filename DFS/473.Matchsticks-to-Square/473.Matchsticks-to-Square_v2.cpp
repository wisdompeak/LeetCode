class Solution {
    bool divide2(vector<int>& sticks, int target) {
        int n = sticks.size();
        for(int state = 0; state < (1<<n); ++state) {
            int cur = 0;
            for(int i = 0; i < n; ++i) {
                if((state>>i)&1) cur += sticks[i];
            }
            if(cur == target) return true;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 != 0) return false;

        int n = matchsticks.size();

        for(int state = 0; state < (1<<n); ++state) {
            int cur = 0;
            for(int i = 0; i < n; ++i) {
                if((state>>i)&1) cur += matchsticks[i];
            }
            if(cur == total / 2) {
                vector<int> v1, v2;
                for(int i = 0; i < n; ++i) {
                    if((state>>i)&1) v1.push_back(matchsticks[i]);
                    else v2.push_back(matchsticks[i]);
                }

                if(divide2(v1, total / 4) && divide2(v2, total / 4)) return true;
            }
        }
        
        return false;
    }
};
