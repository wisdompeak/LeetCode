class Solution {
    unordered_map<string,int>Map;
    int N;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        N=price.size();
        vector<vector<int>>specials;
        for (int i=0; i<special.size(); i++)
        {
            int sum=0;
            for (int j=0; j<N; j++)
                sum+=special[i][j]*price[j];
            if (sum>special[i].back())
                specials.push_back(special[i]);
        }
                
        string key;
        for (int i=0; i<N; i++)
            key+="0";
        Map[key]=0;
        
        return DFS(price,specials,needs);        
    }
    
    string getKey(vector<int>& needs)
    {
        string key;
        for (int i=0; i<needs.size(); i++)
            key+=to_string(needs[i]);
        return key;
    }
    
    int DFS(vector<int>& price, vector<vector<int>>& specials, vector<int>& needs)
    {
        string key=getKey(needs);
        if (Map.find(key)!=Map.end())
            return Map[key];
        
        int result=INT_MAX;
        int special_used=0;
        for (int i=0; i<specials.size(); i++)
        {
            int flag=1;
            for (int j=0; j<N; j++)
            {
                if (specials[i][j]>needs[j])
                {
                    flag=0;
                    break;
                }
            }
            if (flag==1)
            {
                special_used=1;
                vector<int> needs_temp = needs;
                for (int j=0; j<N; j++)
                    needs_temp[j]=needs[j]-specials[i][j];                
                result=min(result,specials[i][N]+DFS(price,specials,needs_temp));
            }
        }
        if (special_used==0)
        {
            result=0;
            for (int i=0; i<N; i++)
                result+=price[i]*needs[i];
        }
        Map[key]=result;   
        
        return result;
    }        
};
