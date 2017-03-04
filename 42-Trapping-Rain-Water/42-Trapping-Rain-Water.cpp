class Solution {
public:
    int trap(vector<int>& height) 
    {
        int N=height.size();
        if (N==0) return 0;
        
        vector<int>LeftMost(N,0);
        vector<int>RightMost(N,0);
        
        for (int i=1; i<N; i++)
            LeftMost[i]=max(LeftMost[i-1],height[i-1]);
        for (int i=N-2; i>=0; i--)    
            RightMost[i]=max(RightMost[i+1],height[i+1]);
            
        int result=0;
        for (int i=1; i<N; i++)
        {
            int temp=min(LeftMost[i],RightMost[i])-height[i];
            if (temp<0) temp=0;
            result+=temp;
        }
        
        return result;
    }
};
