class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        long long sum = 0;
        priority_queue<int>pq;
        for (int i=0; i<target.size(); i++)
        {
            pq.push(target[i]);
            sum+=target[i];
        }
        
        while (pq.top()!=1)
        {
            long long a = pq.top();
            long long others = sum - a;
            pq.pop();

            if (others ==0) return false;
            if (a - others <= 0) return false;
            long long b = a % others;
            
            sum = others + b;
            pq.push(b);            
        }     
        return true;
    }
};
