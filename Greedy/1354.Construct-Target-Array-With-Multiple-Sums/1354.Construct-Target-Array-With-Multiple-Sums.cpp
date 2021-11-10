class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        priority_queue<int>pq;
        for (auto x: target) pq.push(x);
        long long sum = 0;
        for (auto x: target) 
            sum += x;
        
        while (pq.top()!=1)
        {
            long long a = pq.top();
            pq.pop();
            long long others = sum - a;
            
            if (others == 0) return false;      
            if (a<=others) return false;
            long long b = a % others;
            if (b==0) b = others;
            
            sum = others+b;
            pq.push(b);
        }
        
        return true;        
    }
};
