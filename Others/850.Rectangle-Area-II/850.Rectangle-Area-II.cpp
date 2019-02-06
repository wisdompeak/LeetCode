class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        set<int>SetX;
        set<int>SetY;
        for (auto coordinate: rectangles)
        {
            SetX.insert(coordinate[0]);
            SetX.insert(coordinate[2]);
            SetY.insert(coordinate[1]);
            SetY.insert(coordinate[3]);
        }
        vector<int>X(SetX.begin(),SetX.end());
        vector<int>Y(SetY.begin(),SetY.end());
        
        int M = X.size();
        int N = Y.size();
        auto points = vector<vector<bool>>(M,vector<bool>(N,0));
        
        for (int k=0; k<rectangles.size(); k++)
        {
            int idx_X_0 = lower_bound(X.begin(),X.end(),rectangles[k][0]) - X.begin();
            int idx_Y_0 = lower_bound(Y.begin(),Y.end(),rectangles[k][1]) - Y.begin();
            int idx_X_1 = lower_bound(X.begin(),X.end(),rectangles[k][2]) - X.begin();
            int idx_Y_1 = lower_bound(Y.begin(),Y.end(),rectangles[k][3]) - Y.begin();
            for (int i=idx_X_0+1; i<=idx_X_1; i++)
                for (int j=idx_Y_0+1; j<=idx_Y_1; j++)
                    points[i][j] = 1;
        }
        
        long long  MOD = 1e9+7;
        long long sum = 0;
        for (int i=1; i<M; i++)
            for (int j=1; j<N; j++)
            {
                if (points[i][j])
                    sum = (sum + (long long)(X[i]-X[i-1])*(long long)(Y[j]-Y[j-1])) % MOD;
                
            }
                
        return sum;
    }
};
