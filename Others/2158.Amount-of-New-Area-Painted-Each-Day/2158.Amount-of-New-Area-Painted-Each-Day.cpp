using AI3 = array<int,3>;
class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) 
    {
        vector<AI3>arr;
        for (int i=0; i<paint.size(); i++)
        {
            arr.push_back({paint[i][0], 1, i});
            arr.push_back({paint[i][1], 0, i});
        }
        sort(arr.begin(), arr.end());
        
        set<int>Set;
        int n = paint.size();
        vector<int>rets(n);
        for (int i=0; i<arr.size(); i++)
        {
            int j = i;
            while (j<arr.size() && arr[j][0]==arr[i][0])
            {
                if (arr[j][1]==1)
                    Set.insert(arr[j][2]);
                else
                    Set.erase(arr[j][2]);
                j++;
            }
            if (!Set.empty())            
                rets[*Set.begin()] += arr[j][0]-arr[i][0];                                        
            i = j-1;
        }
        
        return rets;
        
    }
};
