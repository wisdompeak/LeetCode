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
       
        vector<pair<int,char>>temp;
        string result;
        int count=0;

        while (!q.empty())
        {
            result+=q.top().second;
            if (q.top().first>1)
            {
                temp.push_back(q.top());
                temp.back().first--;                
            }
            q.pop();
            count++;
            
            if (count==k)
            {
                for (int i=0; i<temp.size(); i++)
                    q.push(temp[i]);
                temp.clear();
                count=0;
            }
        }
        
        if (result.size()<s.size())
            return "";
        else
            return result;               
    }
};
