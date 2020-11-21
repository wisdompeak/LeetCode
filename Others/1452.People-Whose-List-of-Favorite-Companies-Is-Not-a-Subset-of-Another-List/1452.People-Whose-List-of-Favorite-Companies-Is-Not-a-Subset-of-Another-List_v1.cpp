class Solution {
    static bool cmp(pair<unordered_set<string>, int>&a, pair<unordered_set<string>, int>&b)
    {
        return a.first.size() > b.first.size();
    }

public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<pair<unordered_set<string>, int>>arr; // {companiyset, personId}
        for (int i=0; i<favoriteCompanies.size(); i++)
        {
            unordered_set<string>Set(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
            arr.push_back({Set, i});
        }
        sort(arr.begin(), arr.end(), cmp);

        vector<int>rets;
        for (int i=0; i<arr.size(); i++)
        {
            int flag = 1;
            for (int j=0; j<i; j++)
            {                
                bool include = 1;  // check if i-th set is included in j-th set
                for (auto c: arr[i].first)
                {
                    if (arr[j].first.find(c)==arr[j].first.end())
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
            if (flag==1) rets.push_back(arr[i].second);
        }

        sort(rets.begin(), rets.end());
        return rets;
    }  

};
