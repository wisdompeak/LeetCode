class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int M=matrix.size();
        int N=matrix[0].size();
        
        auto hist = vector<int>(N,0);
        int result=0;
        
        for (int i=0; i<M; i++)
        {
            for (int k=0; k<N; k++)
            {                
                if (matrix[i][k]=='1')
                    hist[k]=hist[k]+1;
                else
                    hist[k]=0;
            }            
            result = max(result,largestRectangleArea(hist));            
        }
        
        return result;
    }
    
    int largestRectangleArea(vector<int> heights) 
    {        
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        stack<int>Stack;
        int result = 0;
        for (int i=0; i<heights.size(); i++)
        {
            while (!Stack.empty() && heights[Stack.top()] > heights[i])
            {
                int H = heights[Stack.top()];
                Stack.pop();                    
                result = max(result, H*(i-Stack.top()-1));                    
            }
            Stack.push(i);            
        }
        return result;        
    }
};
