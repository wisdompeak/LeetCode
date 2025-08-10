using PII = pair<int,int>;

class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();

        unordered_set<int>purged;
        unordered_map<int,int>Map; // value -> How many active elements whose limit is the key
        
        vector<PII> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({value[i], limit[i]});
        }
        sort(arr.begin(), arr.end(), [](PII&a, PII&b){
            if (a.second!=b.second)
                return a.second < b.second;
            else
                return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<int>> pq; 

        long long ret = 0;
        int active = 0;
        
        for (auto& [V,L] : arr) {
            if (purged.find(L)!=purged.end())
                continue;
            
            if (L > active) {
                ret += V;
                pq.push(V);
                active += 1;                 
                Map[L]+=1;
                
                purged.insert(active);                                
                int temp = Map[active];
                Map[active] = 0;
                active -= temp;                
            } else if (!pq.empty() && V > pq.top()) {
                ret -= pq.top();
                 pq.pop();
                ret += V; 
                pq.push(V);
                Map[L]+=1;
            }
        }

        return ret;
    }
};
