class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) 
    {
        if (height.size()==0) return 0;
        if (height.size()==1) return height[0];
        
        height.push_back(0);
        height.insert(height.begin(),0);
        stack<int>s;

        int result=0;
        
        for (int i=0; i<height.size(); i++)
        {

            if (s.empty() || height[i]>=height[s.top()])
            {
                s.push(i);
                continue;
            }

            if (height[i]<height[s.top()])
            {
                while (!s.empty() && height[s.top()]>height[i])
                {
                    
                    int Height = height[s.top()];
                    s.pop();
                    result = max(result, Height*(i-s.top()-1));

                }
                s.push(i);
            }            
        }
        
        return result;
    }
};
