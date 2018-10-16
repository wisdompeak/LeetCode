class Solution {
public:
    string rearrangeString(string s, int k) 
    {
        if (k==0) return s;
        unordered_map<char,int>Map;
        for (auto ch:s) Map[ch]++;
        priority_queue<pair<int,char>>pq;
        for (auto a:Map) pq.push({a.second,a.first});
        
        string result;
        while (!pq.empty())
        {
            int n = min(k, (int)pq.size());
            vector<pair<int,char>>temp;
            
            for (int i=0; i<n; i++)
            {
                int num = pq.top().first;
                int ch = pq.top().second;
                pq.pop();
                result+=ch;
                num--;
                if (num!=0) temp.push_back({num,ch});
            }
            if (n<k && temp.size()>0) return "";
            for (auto a:temp) pq.push(a);
        }
        return result;
    }
};
