class AutocompleteSystem {
    unordered_map<string,int>Map;
    string data;
    
    struct cmp
    {
        bool operator()(pair<string,int>a, pair<string,int>b)
        {
            if (a.second==b.second)
                return a.first<b.first;
            else
                return a.second>b.second;
        }
    };
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) 
    {
        for (int i=0; i<sentences.size(); i++)
            Map[sentences[i]]=times[i];
        data.clear();
    }
    
    vector<string> input(char c) 
    {
        if (c=='#')
        {
            Map[data]++;
            data.clear();
            return {};
        }
        
        data.push_back(c);
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq;        
        
        for (auto x:Map)
        {
            string a=x.first;
            if (match(data,a))
            {                
                pq.push({a,Map[a]});
                if (pq.size()>3) pq.pop();
            }
        }
        
        vector<string>results;
        while (!pq.empty())
        {
            results.push_back(pq.top().first);
            pq.pop();
        }
        reverse(results.begin(),results.end());
        return results;
    }
    
    bool match(string a, string b)
    {
        for (int i=0; i<a.size(); i++)
        {
            if (i>=b.size() || a[i]!=b[i])
                return false;
        }
        return true;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
