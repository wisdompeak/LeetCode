class Solution {
public:
    bool isSelfCrossing(vector<int>& x) 
    {
        x.insert(x.begin(), 4, 0);
        
        int i = 4;
        while (i<x.size() && x[i]>x[i-2])
            i++;
        if (i==x.size()) return false;
        
        if (x[i] >= x[i-2]-x[i-4])
            x[i-1] = x[i-1] - x[i-3];
        i++;
        
        while (i<x.size() &&  x[i]<x[i-2])
            i++;
        
        if (i==x.size()) return false;
        else return true;
    }
};
