class Solution {
public:
    string rearrangeString(string s, int k) 
    {
        if (k==0) return s;
        
        unordered_map<char,int>Map;
        for (int i=0; i<s.size(); i++)
            Map[s[i]]++;
        
        priority_queue<pair<int,char>>q;
        for (auto a:Map)
            q.push({a.second,a.first});
            
        string result;
        while (q.size()>=k)
        {
            vector<pair<int,char>>temp;
            
            for (int i=0; i<k; i++)
            {
                result+=q.top().second;
                temp.push_back(q.top());
                temp.back().first--;
                q.pop();
            }
            for (int i=0; i<k; i++)
            {
                if (temp[i].first>0)
                    q.push(temp[i]);
            }
        }
        
        if (q.empty()) return result;
        
        if (q.top().first>1) 
        {
            result="";
            return result;
        }
        
        while (!q.empty())
        {
            result+=q.top().second;
            q.pop();
        }
        return result;
        
    }
};
