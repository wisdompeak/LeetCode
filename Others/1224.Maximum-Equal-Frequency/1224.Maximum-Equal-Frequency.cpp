class Solution {
public:
    int maxEqualFreq(vector<int>& nums) 
    {        
        unordered_map<int,int>num2freq;
        for (auto num: nums)
            num2freq[num]++;
        
        unordered_map<int,int>freq2count;
        for (auto [num, freq]:num2freq)
            freq2count[freq] += 1;
        
        
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (freq2count.size()==1)
            {
                auto [freq, count] = *freq2count.begin();
                if (count == 1 || freq == 1)
                    return i+1;                                            }                
            else if (freq2count.size()==2)
            {
                vector<pair<int,int>>temp(freq2count.begin(), freq2count.end());
                sort(temp.begin(), temp.end());            
                
                if (temp[1].first == temp[0].first + 1 && temp[1].second == 1)
                    return i+1;
                if (temp[0].first == 1 && temp[0].second == 1)
                    return i+1;         
            }
            
            int x = nums[i];
            int f = num2freq[x];
                        
            num2freq[x] -= 1;
            if (num2freq[x]==0)
                num2freq.erase(x);
            
            freq2count[f] -= 1;
            if (freq2count[f] == 0)
                freq2count.erase(f);
            
            if (f-1>0)
                freq2count[f-1] += 1;
        }
        
        return 2;
    }
};
