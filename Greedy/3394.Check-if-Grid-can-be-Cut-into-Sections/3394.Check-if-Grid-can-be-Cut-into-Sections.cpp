class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& arr) 
    {
        vector<vector<int>>widths;
        vector<vector<int>>heights;
        for (int i=0; i<arr.size(); i++)
        {
            widths.push_back({arr[i][0], arr[i][2]});
            heights.push_back({arr[i][1], arr[i][3]});            
        }
        if (check(widths)) return true;        
        if (check(heights)) return true;
        return false;        
    }

    bool check(vector<vector<int>>&arr)
    {
        sort(arr.begin(),arr.end());
                        
        int j=0;        
        int count = 0;
        for (int i=0; i<arr.size();)
        {
            int far = arr[i][1];
            while (j<arr.size() && arr[j][0]<far)
            {
                far = max(far, arr[j][1]);
                j++;
            }                
            count++;            
            i = j;  
            if (count>=3) return true;          
        }
        return false;
    }
};
