using LL = long long;
using AI3 = array<LL,3>;
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) 
    {
        vector<AI3>arr;
        for (auto seg: segments)
        {
            arr.push_back({seg[0], 1, seg[2]});
            arr.push_back({seg[1], -1, seg[2]});
        }        
        sort(arr.begin(), arr.end());
                
        LL sum = 0;
        LL start = -1, end = -1;
        vector<vector<LL>>rets;
                        
        for (int i=0; i<arr.size(); i++)
        {
            if (start == -1)            
                start = arr[i][0];            
            else
            {
                end = arr[i][0];                
                rets.push_back({start, end, sum});                
                start = end;                                
            }
            
            int j = i;                        
            while (j<arr.size() && arr[j][0]==arr[i][0])
            {
                if (arr[j][1]==1)                
                    sum += arr[j][2];                    
                else                
                    sum -= arr[j][2];                
                j++;
            }
                        
            if (sum == 0)
                start = -1;
            
            i = j-1;
        }
        
        return rets;
    }
};
