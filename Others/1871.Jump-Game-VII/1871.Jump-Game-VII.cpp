class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if(s.back()!='0') return false;

        int n = s.size();
        vector<int>diff(n+1);
        int visit = 0;
        diff[minJump] += 1;
        diff[maxJump+1] -= 1;

        for (int i=1; i<n; i++)
        {
            visit += diff[i];

            if (visit==0) continue;
            if (s[i]=='1') continue;

            if (i+minJump<=n) diff[i+minJump] += 1;
            if (i+maxJump+1<=n) diff[i+maxJump+1] -= 1;
        }

        return visit;
    }
};
