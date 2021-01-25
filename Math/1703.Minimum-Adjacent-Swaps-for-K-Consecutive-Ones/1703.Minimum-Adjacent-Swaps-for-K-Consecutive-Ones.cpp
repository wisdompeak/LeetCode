class Solution {
public:
    int minMoves(vector<int>& nums, int k) 
    {
        vector<int>p;
        for (int i=0; i<nums.size(); i++)
            if (nums[i]==1)
                p.push_back(i);
        
        int sum = 0;
        for (int i=0; i<k; i++)
            sum += abs(p[i]-p[k/2]);
        int ret = sum;

        for (int i=0; i+k<p.size(); i++)
        {            
            int mid = i+k/2;
            sum -= abs(p[i]-p[mid]);
            sum += abs(p[mid+1]-p[mid]) * (k/2);
            sum += abs(p[i+k] - p[mid+1]);
            sum -= abs(p[mid+1]-p[mid]) * (k-k/2-1);
            ret = min(ret, sum);
        }

        int offset = 0;
        for (int i=0; i<k; i++)
            offset += abs(i-k/2);

        return ret-offset;
    }
};

//    0  1 2  k/2       k
// X  X X  O   X   X 
//    X X  X   O   X X
