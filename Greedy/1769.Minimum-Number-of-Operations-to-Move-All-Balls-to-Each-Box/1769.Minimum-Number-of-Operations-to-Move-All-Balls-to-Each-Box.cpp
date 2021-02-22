class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int>leftMoves(n);
        vector<int>rightMoves(n);
        int left = 0;
        for (int i = 1; i<n; i++)
        {
            left += (boxes[i-1]=='1');
            leftMoves[i] = leftMoves[i-1] + left*1;
        }
        int right = 0;
        for (int i = n-2; i>=0; i--)
        {
            right += (boxes[i+1]=='1');
            rightMoves[i] = rightMoves[i+1] + right*1;
        }
        vector<int>rets(n);
        for (int i=0; i<n; i++)
            rets[i] = leftMoves[i]+rightMoves[i];
        return rets;
    }
};
