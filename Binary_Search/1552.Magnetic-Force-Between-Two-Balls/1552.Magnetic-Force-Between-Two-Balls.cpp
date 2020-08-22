class Solution {
public:
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(), position.end());
        int left = 1, right = position.back()-position[0];
        while (left<right)
        {
            int mid = right-(right-left)/2;
            if (isOK(position, mid, m))
                left = mid;
            else
                right = mid-1;
        }
        return left;        
    }
    
    bool isOK(vector<int>& position, int len, int m)
    {
        int j=0;
        int count = 1;
        
        for (int i=0; i<position.size(); )
        {
            j = i;
            while (j<position.size() && position[j]-position[i]<len)
                j++;
                        
            if (j==position.size()) 
                break;
            else
            {
                count++;                
                i=j;
            }
            if (count==m) return true;
            
        }
        return false;
    }
};
