class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int best = 0;

        int run = 1;
        for (int i=1; i<n; i++) {
            if (s[i]==s[i-1]) 
                run++;
            else {
                best = max(best, run);
                run = 1;
            }                
        }
        best = max(best, run);

        for (char skip: {'a','b','c'}) {
            int i = 0;
            while (i<n) {
                while (i<n && s[i]==skip) i++;
                if (i>=n) break;
                int j = i;
                while (j<n && s[j]!=skip) j++;

                if (j-i>=2) {
                    unordered_map<int,int>first;
                    first[0] = i-1;
                    int diff = 0;
                    char c1 = s[i];
                    for (int k=i; k<j; k++) {
                        if (s[k]==c1) diff++;
                        else diff--;
                        if (first.find(diff)!=first.end()) {
                            int len = k-first[diff];                            
                            best = max(best, len);
                        } else {
                            first[diff] = k;
                        }
                    }
                }
                i = j;
            }            
        }

        map<pair<int,int>, int>Map;
        Map[{0,0}] = -1;
        int ca=0, cb=0, cc=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='a') ca++;
            else if (s[i]=='b') cb++;
            else cc++;
            if (Map.find({ca-cb, ca-cc})!=Map.end()) {
                int len = i - Map[{ca-cb,ca-cc}];
                best = max(best, len);
            } else {
                Map[{ca-cb,ca-cc}] = i;
            }
        }

        return best;
    }
};
