using ll = long long;
class Solution {
    vector<ll>arr;
    int next[15000];
    int n;
    ll side;
public:
    ll pos(int j) {
        if (j<n)
            return arr[j];
        else
            return arr[j%n] + side*4;
    }

    bool isOK(int dist, int k) {
        int j = 0;
        for (int i=0; i<n; i++) {
            while (pos(j)-arr[i]<dist)
                j++;
            next[i] = j;
        }

        for (int i=0; i<n; i++) {
            int flag = true;
            int cur = i;
            for (int t=0; t<k-1; t++) {
                if (cur<n)
                    cur = next[cur];
                else
                    cur = next[cur%n] + n;
                if (cur >= i+n) {
                    flag = false;
                    break;
                }
            }
            if (pos(i)-pos(cur%n)<dist) {
                flag =false;
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }


    int maxDistance(int side, vector<vector<int>>& points, int k) {        
        this->n = points.size();
        this->side = side;
        for (auto& p: points) {
            if (p[0]==0) 
                arr.push_back(p[1]);
            else if (p[1]==side)
                arr.push_back(side+p[0]);
            else if (p[0]==side)
                arr.push_back(2ll*side+side-p[1]);
            else if (p[1]==0)
                arr.push_back(3ll*side+side-p[0]);
        }

        sort(arr.begin(), arr.end());

        int low = 0, high = side;
        while (low < high) {
            int mid = high - (high-low)/2;
            if (isOK(mid, k)) 
                low = mid;
            else
                high = mid-1;
        }
        return low;
    }
};
