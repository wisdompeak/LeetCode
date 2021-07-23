class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>freq;
        for (auto x: nums)
            freq[x]++;

        vector<pair<int,int>>arr;
        for (auto x: freq)
            arr.push_back(x);

        int f = quickselect(arr, 0, arr.size()-1, k);

        vector<int>rets;
        for (auto x: arr)
        {
            if (x.second >= f)
                rets.push_back(x.first);
        }
        return rets;
    }

    int quickselect(vector<pair<int,int>>arr, int a, int b, int k)
    {
        int pivot = arr[(a+b)/2].second;
        int i=a, j=b, t=a;
        while (t<=j)
        {
            if (arr[t].second > pivot)
            {
                swap(arr[j], arr[t]);
                j--;
            }
            else if (arr[t].second < pivot)
            {
                swap(arr[i], arr[t]);
                i++;
                t++;
            }
            else
            {
                t++;
            }
        }

        if (b-j>=k) return quickselect(arr, j+1, b, k);
        else if (b-i+1>=k) return pivot;
        else return quickselect(arr, a, i-1, k-(b-i+1));
    }
};
