class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) 
    {
        int n = boxes.size();
        boxes.insert(boxes.begin(), {-1,0});
        vector<int>dp(n+1, INT_MAX/2);
        dp[0] = 0;

        int j = 0;
        int weightSum = 0;
        int tripSum = 0;
        int lastPort = -1; 
        int lastj;
        for (int i=1; i<=n; i++)
        {         
            // find the longest valid window [i:j]
            while (j+1<=n && j+1-i+1 <= maxBoxes && weightSum + boxes[j+1][1] <= maxWeight)
            {
                j+=1;
                weightSum += boxes[j][1];
                if (boxes[j][0]!=boxes[j-1][0])
                    tripSum += 1;                
                if (boxes[j][0]!=lastPort)
                {
                    lastPort = boxes[j][0];
                    lastj = j;
                }                
            }
            // update dp[j]
            dp[j] = min(dp[j], dp[i-1] + tripSum + 1);
            // in some cases, update dp[lastj-1], where [lastj:j] share the same port.
            if (j+1<=n && boxes[j][0]==boxes[j+1][0])
            {
                dp[lastj-1] = min(dp[lastj-1], dp[i-1] + tripSum);
            }
            weightSum -= boxes[i][1];
            tripSum -= (i+1<=n && boxes[i][0]!=boxes[i+1][0]);
                
        }
        return dp[n];
    }
};

