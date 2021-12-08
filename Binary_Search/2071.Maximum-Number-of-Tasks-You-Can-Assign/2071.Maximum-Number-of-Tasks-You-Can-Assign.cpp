class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = tasks.size();
        while (left < right)
        {
            int mid = right - (right - left)/2;
            if (checkOK(tasks, workers, pills, strength, mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;        
    }
    
    bool checkOK(vector<int>& tasks, vector<int>& workers, int pills, int strength, int num)
    {
        if (num > tasks.size()) return false;
        if (num > workers.size()) return false;
        
        multiset<int>Set(workers.begin(), workers.end());        
                
        for (int i=num-1; i>=0; i--)
        {            
            if (*Set.rbegin() >= tasks[i])            
            {
                Set.erase(prev(Set.end()));
            }
            else 
            {
                if (pills == 0) return false;
                auto iter = Set.lower_bound(tasks[i]-strength);
                if (iter == Set.end()) return false;
                Set.erase(iter);                
                pills--;
            }
        }
        return true;
    }
};
