class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) 
    {
        vector<int>rets;
        if (dfs(sums, n, rets))
            return rets;       
        return {};
    }
    
    vector<int>split1(vector<int>&sums, int x)
    {        
        int k = sums.size();
        vector<int>visited(k);
        vector<int>rets;
        int i = k-1, j = k-1;
        for (int t=0; t<k/2; t++)
        {
            while (i>=0 && visited[i])
                i--;
            if (i<0) return {};
            visited[i] = 1;
            
            while (j>=0 && (visited[j]||sums[j]!=sums[i]-x))
                j--;
            if (j<0) return {};
            visited[j] = 1;
            
            rets.push_back(sums[j]);
        }
        return rets;
    }      
    
    vector<int>split2(vector<int>&sums, int x)
    {
        int k = sums.size();
        vector<int>visited(k);
        vector<int>rets;
        int i = 0, j = 0;
        for (int t=0; t<k/2; t++)
        {
            while (i<k && visited[i])
                i++;
            if (i>=k) return {};
            visited[i] = 1;
            
            while (j<k && (visited[j]||sums[j]!=sums[i]-x))
                j++;
            if (j>=k) return {};
            visited[j] = 1;
            
            rets.push_back(sums[j]);
        }
        return rets;
    }    
    
    
    bool dfs(vector<int>sums, int n, vector<int>&rets)
    {
        if (n==1)
        {
            if (sums[0]!=0 && sums[1]!=0)
                return false;
            else
            {
                rets.push_back(sums[0]==0? sums[1]:sums[0]);
                return true;
            }
        }
        
        int k = sums.size();
        sort(sums.begin(), sums.end());
        
        // suppose x is the minimum positive number
        int x = sums[k-1]-sums[k-2]; 
        vector<int>sums1 = split1(sums, x);
        if (sums1.size()==k/2)
        {
            rets.push_back(x);
            if (dfs(sums1, n-1, rets))
                return true;
            rets.pop_back();
        }
        
        // suppose x is the maximum negative number
        x = -(sums[k-1]-sums[k-2]);
        vector<int>sums2 = split2(sums, x);
        if (sums2.size()==k/2)
        {
            rets.push_back(x);
            if (dfs(sums2, n-1, rets))
                return true;
            rets.pop_back();
        }    
                
        return false;        
    }    
};
