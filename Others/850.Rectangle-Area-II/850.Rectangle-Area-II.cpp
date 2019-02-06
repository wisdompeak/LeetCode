class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        set<int>SetX;
        set<int>SetY;
        for (auto point: rectangles)
        {
            SetX.insert(point[0]);
            SetX.insert(point[2]);
            SetY.insert(point[1]);
            SetY.insert(point[3]);
        }
        
        vector<int>X(SetX.begin(),SetX.end());
        vector<int>Y(SetY.begin(),SetY.end());
        
        int M = X.size();
        int N = Y.size();
        auto points = vector<vector<bool>>(M,vector<bool>(N,0));
        
        for (auto p: rectangles)
        {
            int x0 = lower_bound(X.begin(),X.end(),p[0])-X.begin();
            int x1 = lower_bound(X.begin(),X.end(),p[2])-X.begin();
            int y0 = lower_bound(Y.begin(),Y.end(),p[1])-Y.begin();
            int y1 = lower_bound(Y.begin(),Y.end(),p[3])-Y.begin();
            for (int i = x0; i<x1; i++)
             for (int j = y0; j<y1; j++)
               points[i][j]=1;
        }
        
        long long result = 0;
        int Mod = 1e9+7;
        for (int i=0; i<M-1; i++)
          for (int j=0; j<N-1; j++)
          {
             if (points[i][j]==0) continue;
             result += (long long)(X[i+1]-X[i]) * (long long)(Y[j+1]-Y[j]);            
             result = result%Mod;
          }
        return result;
    }
};
