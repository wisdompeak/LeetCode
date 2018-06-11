class Solution {
    long long MOD = 1e9+7;
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        int N=rectangles.size();
        vector<int>X;
        vector<int>Y;
        for (int i=0; i<N; i++)
        {
            X.push_back(rectangles[i][0]);
            X.push_back(rectangles[i][2]);
            Y.push_back(rectangles[i][1]);
            Y.push_back(rectangles[i][3]);
        }
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        
        vector<vector<bool>>points(X.size(),vector<bool>(Y.size(),false));
        for (int i=0; i<N; i++)
        {
            int idx_X_0 = lower_bound(X.begin(),X.end(),rectangles[i][0])-X.begin();
            int idx_Y_0 = lower_bound(Y.begin(),Y.end(),rectangles[i][1])-Y.begin();
            int idx_X_1 = lower_bound(X.begin(),X.end(),rectangles[i][2])-X.begin();
            int idx_Y_1 = lower_bound(Y.begin(),Y.end(),rectangles[i][3])-Y.begin();
            
            for (int u=idx_X_0; u<idx_X_1; u++)
                for (int v=idx_Y_0; v<idx_Y_1; v++)
                    points[u][v]=true;            
        }
        
        long long result = 0;
        for (int i=0; i<X.size(); i++)
            for (int j=0; j<Y.size(); j++)
            {
                if (points[i][j])
                {
                    result = result + (long long)(X[i+1]-X[i])*(long long)(Y[j+1]-Y[j])%MOD;
                }
                    
            }
        return result%MOD;                
    }
};
