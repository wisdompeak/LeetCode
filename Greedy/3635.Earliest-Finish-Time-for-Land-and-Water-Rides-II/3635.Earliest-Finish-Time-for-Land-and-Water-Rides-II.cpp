class Solution {
public:
    int solve(vector<pair<int,int>>& A, vector<pair<int,int>>& B) {
        int n = A.size();
        int ret = INT_MAX;        
        int minEnd = INT_MAX;
        for (int i=0; i<A.size(); i++) {
            minEnd = min(minEnd, A[i].first+A[i].second);                            
        }
        for (int i=0; i<B.size(); i++) {
            if (B[i].first>=minEnd)
                ret = min(ret, B[i].first+B[i].second);
            else
                ret = min(ret, minEnd+B[i].second);
        }
        return ret;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>>A;
        vector<pair<int,int>>B;
        for (int i=0; i<landStartTime.size(); i++)
        {            
            A.push_back({landStartTime[i], landDuration[i]});                
        }
        for (int i=0; i<waterStartTime.size(); i++)
        {            
            B.push_back({waterStartTime[i], waterDuration[i]});
        }

        return min(solve(A,B), solve(B,A));
            
    }
};
