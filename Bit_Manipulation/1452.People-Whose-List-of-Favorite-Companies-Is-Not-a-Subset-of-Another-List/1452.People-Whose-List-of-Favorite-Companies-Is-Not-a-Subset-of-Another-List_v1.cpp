class Solution {
    
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<unordered_set<string>>arr; 
        for (int i=0; i<favoriteCompanies.size(); i++)
        {
            unordered_set<string>Set(favoriteCompanies[i].begin(),favoriteCompanies[i].end());
            arr.push_back(Set);
        }

        vector<int>rets;
        for (int i=0; i<arr.size(); i++)
        {
            int flag = 1;
            for (int j=0; j<arr.size(); j++)            
            {                
                if (i==j) continue;
                bool include = 1;  // check if i-th set is included in j-th set
                for (auto c: arr[i])
                {
                    if (arr[j].find(c)==arr[j].end())
                    {            
                        include = 0;            
                        break;
                    }                        
                }
                if (include == 1) // If included, disqualification
                {
                    flag = 0;
                    break;
                }
            }
            if (flag==1) rets.push_back(i);
        }

        return rets;
    }  

};
