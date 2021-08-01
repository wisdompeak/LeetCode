class Solution {
public:
    string reorganizeString(string S) 
    {
        unordered_map<char,int>count;
        for (auto ch:S) count[ch]++;

        priority_queue<pair<int,char>>pq;        
        for (auto x:count) 
            pq.push({x.second, x.first});        
        
        string result;
        while (!pq.empty())
        {
            int k = min(2,(int)pq.size());
            vector<pair<int,char>>temp;
            
            for (int i=0; i<k; i++)
            {
                auto [num, ch] = pq.top(); 
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
