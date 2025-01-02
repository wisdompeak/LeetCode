class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) 
    {
        int ret = 0;
        int n = nums1.size();
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<n; i++)
            Map[nums2[i]].push_back(i);

        vector<int>scores(n);
        for (int i=0; i<n; i++)
        {
            for (int idx: Map[nums1[i]])
                scores[(idx-i+n)%n]++;
        }
        return *max_element(scores.begin(), scores.end());
    }
};
