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
        
        unordered_set<LL>Set;
        LL sum = 0;
        LL start = -1, end = -1;
        
        vector<vector<LL>>rets;
        
        for (int i=0; i<arr.size(); i++)
        {
            int j = i;
            
            unordered_map<LL, LL>Map;            
            while (j<arr.size() && arr[j][0]==arr[i][0])
            {
                if (arr[j][1]==1)
                    Map[arr[j][2]]++;
                else
                    Map[arr[j][2]]--;
                
                j++;
            }                        
            
            int flag = 0;
            for (auto x: Map)
                if (x.second!=0)
                {
                    flag = 1;
                    break;
                }
            
            if (flag==0)
            {
                if (!rets.empty() && !Set.empty())
                    rets.back()[1] = arr[i][0];
                
                i = j-1;
                continue;
            }
            
            if (start == -1)
            {
                start = arr[i][0];
            }
            else
            {
                end = arr[i][0];                
                rets.push_back({start, end, sum});                
                start = end;                                
            }
            
            for (auto x: Map)
            {
                auto [color, freq] = x;
                
                if (freq > 0 && Set.find(color)==Set.end())
                {
                    Set.insert(color);
                    sum += color;
                }                    
                else if (freq < 0)
                {
                    Set.erase(color);
                    sum -= color;
                }
            }
            
            if (Set.empty())
                start = -1;
            
            i = j-1;
        }
        
        return rets;

    }
};
