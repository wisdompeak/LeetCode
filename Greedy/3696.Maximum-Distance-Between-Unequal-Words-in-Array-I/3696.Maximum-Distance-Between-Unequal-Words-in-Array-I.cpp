class Solution {
public:
    int maxDistance(vector<string>& words) {        
        int n = words.size();
        if (words[0]!=words.back()) return n;

        int ret = 0;
        for (int i=0; i<n; i++) {
            if (words[i]!=words[0])
                ret = max(ret, i-0+1);
        }

        for (int i=n-2; i>=0; i--) {
            if (words[i]!=words.back())
                ret = max(ret, n-1-i+1);
        }

        return ret;
        
    }
};
