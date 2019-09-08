class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) 
    {
        int n1 = width/sideLength;
        int d1 = width%sideLength;
        int n2 = height/sideLength;
        int d2 = height%sideLength;
        
        auto freq = vector<vector<int>>(sideLength, vector<int>(sideLength,0));
        for (int i=0; i<width; i++)
            for (int j=0; j<height; j++)
            {
                int x = i%sideLength;
                int y = j%sideLength;
                freq[x][y]++;
            }
        
        vector<int>q;
        for (int i=0; i<sideLength; i++)
            for (int j=0; j<sideLength; j++)
                q.push_back(freq[i][j]);
        
        sort(q.begin(),q.end());
        reverse(q.begin(),q.end());
        
        int ret = 0;
        for(int i=0; i<maxOnes; i++)
            ret += q[i];
        
        return ret;            
    }
};
