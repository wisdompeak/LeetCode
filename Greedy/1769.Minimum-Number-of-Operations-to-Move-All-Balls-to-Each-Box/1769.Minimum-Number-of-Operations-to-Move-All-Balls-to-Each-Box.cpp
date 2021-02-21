class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int>leftMoves(n);
        vector<int>rightMoves(n);

        int left = 0;
        for (int i=0; i<n; i++)
        {           
            leftMoves[i] += (i==0 ? 0: leftMoves[i-1]) + left;
            left += (boxes[i]=='1');
        }
        int right = 0;
        for (int i=n-1; i>=0; i--)
        {
            rightMoves[i] += (i==n-1 ? 0: rightMoves[i+1]) + right;
            right += (boxes[i]=='1');
        }
        
        vector<int>rets(n);
        for (int i=0; i<n; i++)
            rets[i] = leftMoves[i] + rightMoves[i];
        return rets;
    }
};
