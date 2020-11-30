class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        int N = A.size();
        int flipNum=0, result = 0;
        vector<int>diff(N+1,0); 
        // 差分数组diff[i]表示A[i]经历的翻转次数，要比A[i-1]经历的反转次数多多少？
        // 所以 flipNum+diff[i] 表示A[i]真正经历翻转的次数
        
        for (int i=0; i<N; i++)
        {
            flipNum+=diff[i];
            if ((A[i]+flipNum)%2==0 && i+K>N) return -1; 
            if ((A[i]+flipNum)%2==1) continue;            
            result++;
            flipNum++;
            diff[i+K]--;  
            // 如果A[i]需要再反转，说明A[i]~A[i+K-1]这个区间多一次翻转，所以diff[i+K]需要减一
        }
        return result;
    }
};
