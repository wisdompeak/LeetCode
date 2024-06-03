class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void build(vector<int>& nums, int node, int start, int end) 
    {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2 * node, start, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] & tree[2 * node + 1];
        }
    }
    
    void update(int node, int start, int end, int L, int R, int val) 
    {
        if (R < start || end < L) {
            return;
        }
        if (L <= start && end <= R) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, L, R, val);
        update(2 * node + 1, mid + 1, end, L, R, val);
        tree[node] = tree[2 * node] & tree[2 * node + 1];
    }

    int query(int node, int start, int end, int L, int R) 
    {
        if (R < start || end < L) {
            return INT_MAX; // Identity for AND operation (all bits set)
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftAnd = query(2 * node, start, mid, L, R);
        int rightAnd = query(2 * node + 1, mid + 1, end, L, R);
        return leftAnd & rightAnd;
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        build(nums, 1, 0, n - 1);
    }

    void rangeUpdate(int L, int R, int val) {
        update(1, 0, n - 1, L, R, val);
    }

    int rangeAnd(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        int n = nums.size();
        SegmentTree segTree(nums);
        int ret = INT_MAX;

        for (int i = 0; i < n; ++i) 
        {            
            int low = i, high = n - 1;
            while (low < high)
            {
                int mid = high - (high - low)/2;
                if (segTree.rangeAnd(i, mid) >= k)
                    low = mid;
                else
                    high = mid-1;
            }
            
            int ret1 = abs(segTree.rangeAnd(i, low) - k);
            int ret2 = INT_MAX;
            if (low+1<n)
                ret2 = abs(segTree.rangeAnd(i, low+1) - k);
            
            ret = min({ret, ret1, ret2});
        }

        return ret;
        
    }
};
