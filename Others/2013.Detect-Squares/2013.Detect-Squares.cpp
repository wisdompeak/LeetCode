class DetectSquares {
    int counts[1005][1005];
public:
    DetectSquares() {
        for (int i=0; i<=1000; i++)
            for (int j=0; j<=1000; j++)
                counts[i][j] = 0;        
    }
    
    void add(vector<int> point) 
    {
        int x = point[0], y = point[1];
        counts[x][y]+=1;
    }
    
    int count(vector<int> point) 
    {
        int x = point[0], y = point[1];
        int ret = 0;
        
        for (int i=0; i<=1000; i++)
        {
            int d = abs(x-i);
            if (d==0) continue;
            int j;
            
            j = y-d;
            if (j>=0 && j<=1000)
                ret += counts[i][j]*counts[i][y]*counts[x][j];
            
            j = y+d;
            if (j>=0 && j<=1000)
                ret += counts[i][j]*counts[i][y]*counts[x][j];  
        }        
        return ret;
    }
    
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
