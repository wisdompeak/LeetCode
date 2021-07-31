using LL = long long;
class Solution {
    vector<pair<LL, int>>arr;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {        
        for (int i=0; i<points.size(); i++)
        {
            long long x1 = points[i][0];
            long long x2 = points[i][1];
            long long d = x1*x1+x2*x2;
            arr.push_back({d, i});
        }
        
        long long d = quickSelect(0, arr.size()-1, K);
                
        vector<vector<int>>rets;
        for (auto x: arr)
        {
            if (x.first <= d)
                rets.push_back(points[x.second]);
        }
        return rets;        
    }
    
    long long quickSelect(int a, int b, int k)
    {
        long long pivot = arr[(a+b)/2].first;
        
        int i = a, j = b, t = a;
        
        while (t<=j)
        {
            if (arr[t].first < pivot)
            {
                swap(arr[i], arr[t]);
                i++;
                t++;
            }
            else if (arr[t].first > pivot)
            {
                swap(arr[j], arr[t]);
                j--;
            }
            else
                t++;
        }
        
        if (i-a >= k) return quickSelect(a, i-1, k);
        else if (j-a+1 >= k) return pivot;
        else return quickSelect(j+1, b, k-(j-a+1));
    }
};
