class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        unordered_map<string,int>skill2num;
        for (int i = 0; i< req_skills.size(); i++)
        {
            skill2num[req_skills[i]] = i;            
        }
        
        vector<int>p2s(people.size());
        for (int i=0; i<people.size(); i++)
        {
            int skillset = 0;
            for (auto skill: people[i])
            {
                if (skill2num.find(skill)==skill2num.end())
                    continue;
                int idx = skill2num[skill];
                skillset += (1<<idx);
            }
            p2s[i] = skillset;
        }
        
        int N = req_skills.size();
        vector<vector<int>>saves(1<<N);  // saves[skillset] : the member ids that fulfill skillset
        vector<int>dp((1<<N), INT_MAX/2);
        
        dp[0] = 0;
        
        for (int i=0; i<people.size(); i++)
        {
            auto dp2 = dp;
            for (int skillset = 0; skillset < (1<<N); skillset++)
            {
                int new_skillset = skillset | p2s[i];
                if (dp2[new_skillset] > dp[skillset]+1)
                {
                    dp2[new_skillset] = dp[skillset]+1;
                    saves[new_skillset] = saves[skillset];
                    saves[new_skillset].push_back(i);
                }
            }
            dp = dp2;
        }
        
        return saves[(1<<N)-1];        
    }
};

