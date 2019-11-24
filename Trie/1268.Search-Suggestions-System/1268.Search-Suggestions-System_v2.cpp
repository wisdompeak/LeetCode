class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(),products.end());
        vector<vector<string>>rets;
        
        string word;        
        for (int i=0; i<searchWord.size(); i++)
        {
            word.push_back(searchWord[i]);
            vector<string>ans;
            auto iter = lower_bound(products.begin(),products.end(),word);
            for (int k=0; k<3; k++)
            {
                if (iter==products.end()) break;
                if (iter->substr(0,word.size())!=word) break;
                ans.push_back(*iter);
                iter = next(iter,1);
            }
            rets.push_back(ans);
        }
        return rets;
    }
};
