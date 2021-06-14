class Solution {
private:
    int dp1[30][30][30];
    int dp2[30][30][30];

public:
    pair<int, int> dp(int n, int a, int b) 
    {
        if (dp1[n][a][b]!=0) {
            return {dp1[n][a][b], dp2[n][a][b]};
        }

        if (a + b == n + 1) {
            return {1, 1};
        }

        if (a > b)
            return dp(n, b, a);

        if (a + b > n + 1) {
            return dp(n, n + 1 - b, n + 1 - a);
        }

        int range1 = a-1;
        int range2;
        int half_point = (n+1)/2;
        int bb = n+1-b;

        int maxVal = INT_MIN/2, minVal = INT_MAX/2;

        if (b > half_point)
        {
            range2 = bb-a-1;
            int mid = b-bb-1;
            for (int x=0; x<=a-1; x++)
                for (int y=0; y<=range2; y++)
                {
                    auto temp = dp((n+1)/2, x+1, x+1+y+(mid+1)/2+1);
                    minVal = min(minVal, temp.first + 1);
                    maxVal = max(maxVal, temp.second + 1);                
                }            
        }
        else {
            range2 = b-a-1;
            for (int x=0; x<=a-1; x++)
                for (int y=0; y<=range2; y++)
                {
                    auto temp = dp((n+1)/2, x+1, x+1+y+1);
                    minVal = min(minVal, temp.first + 1);
                    maxVal = max(maxVal, temp.second + 1);                
                }            
        }
        dp1[n][a][b] = minVal;
        dp2[n][a][b] = maxVal;
        return {minVal, maxVal};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto [earlist, latest] = dp(n, firstPlayer, secondPlayer);
        return {earlist, latest};
    }
};
