class Solution {    
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) 
    {
        int n = *max_element(groups.begin(), groups.end());
        vector<int>arr(n+1, -1);
        
        for (int j=0; j<elements.size(); j++)
        {            
            int x0 = elements[j];
            if (x0>n) continue;
            
            if (arr[x0]!=-1) continue;
            
            int x = x0;            
            while (x<=n)
            {
                if (arr[x]==-1)
                    arr[x] = j;
                x+=x0;                    
            }
        }
        
        vector<int>rets;
        for (int g: groups)
            rets.push_back(arr[g]);
        return rets;
    }
};
