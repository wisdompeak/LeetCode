class Solution {
public:
    int convertTime(string current, string correct) 
    {
        int h1 = stoi(current.substr(0,2));
        int m1 = stoi(current.substr(3));
        
        int h2= stoi(correct.substr(0,2));
        int m2 = stoi(correct.substr(3));
        
        int delta = (h2-h1)*60+(m2-m1);
        
        int ret = INT_MAX;
        
        for (int i=0; i*60<=delta; i++)
            for (int j=0; j*15+i*60<=delta; j++)
                for (int k=0; k*5+j*15+i*60<=delta; k++)
                ret = min(ret, i+j+k+delta-(k*5+j*15+i*60));
        
        return ret;
               
    }
};
