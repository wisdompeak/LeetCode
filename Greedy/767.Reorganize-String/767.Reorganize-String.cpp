class Solution {
public:
    string reorganizeString(string S) 
    {
        unordered_map<char,int>Map;
        for (auto ch:S) Map[ch]++;
        priority_queue<pair<int,char>>pq;        
        for (auto a:Map) pq.push({a.second,a.first});        
        
        string result;
        while (!pq.empty())
        {
            int k = min(2,(int)pq.size());
            vector<pair<int,char>>temp;
            
            for (int i=0; i<k; i++)
            {
                int ch = pq.top().second;
                int num = pq.top().first;
                pq.pop();
                result+=ch;
                num--;
                if (num!=0) temp.push_back({num,ch});                
            }
            if (k<2 && temp.size()>0) return "";
            for (auto a:temp) pq.push(a);
        }
        return result;
    }
};
