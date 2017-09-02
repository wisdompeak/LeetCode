class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        vector<int>Mins;
        vector<int>Maxs;
        for (int i=0; i<arrays.size(); i++)
        {
            Mins.push_back(arrays[i][0]);
            Maxs.push_back(arrays[i].back());
        }
        
        sort(Mins.begin(),Mins.end());
        sort(Maxs.begin(),Maxs.end());
        
        int N=arrays.size();
        int flag=0;
        for (int i=0; i<arrays.size(); i++)
        {
            if (arrays[i][0]==Mins[0] && arrays[i].back()==Maxs.back() )
            {
                flag=1;
                break;                    
            }            
        }
        
        if (flag==0)
            return Maxs.back()-Mins[0];
        else
            return max(Maxs.back()-Mins[1],Maxs[N-2]-Mins[0]);
    }
};
