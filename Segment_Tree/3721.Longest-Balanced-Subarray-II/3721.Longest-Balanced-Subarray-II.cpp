class Solution {

struct SegTree{
    int n;  
    struct Node {int mn, mx, lazy;};
    vector<Node>st;
    SegTree(int _n=0) {init(_n);}
    void init(int _n) {
        n = _n;
        st.assign(4*(n+5), {0,0,0});        
    }
    void apply(int p, int val){
        st[p].mn += val;
        st[p].mx += val;
        st[p].lazy += val;
    }
    void push(int p){
        if(st[p].lazy){
            apply(p<<1, st[p].lazy);
            apply(p<<1|1, st[p].lazy);
            st[p].lazy = 0;
        }
    }
    void pull(int p){
        st[p].mn = min(st[p<<1].mn, st[p<<1|1].mn);
        st[p].mx = max(st[p<<1].mx, st[p<<1|1].mx);
    }
    void range_add(int p, int l, int r, int L, int R, int val){
        if(L>R || r<L || R<l) return;
        if(L<=l && r<=R){ apply(p, val); return; }
        push(p);
        int m=(l+r)>>1;
        range_add(p<<1, l, m, L, R, val);
        range_add(p<<1|1, m+1, r, L, R, val);
        pull(p);
    }
    void range_add(int L, int R, int val){
        if(L>R) return;
        range_add(1, 0, n, L, R, val);
    }
    int find_first_equal(int p, int l, int r, int L, int R, int target){
        if(L>R || r<L || R<l) return -1;
        if(st[p].mn > target || st[p].mx < target) return -1;
        if(l==r){
            return l;
        }
        push(p);
        int m=(l+r)>>1;
        int res = find_first_equal(p<<1, l, m, L, R, target);
        if(res != -1) return res;
        return find_first_equal(p<<1|1, m+1, r, L, R, target);
    }
    int find_first_equal(int L, int R, int target){
        if(L>R) return -1;
        return find_first_equal(1, 0, n, L, R, target);
    }
    int point_query(int p, int l, int r, int idx){
        if(l==r) return st[p].mn;
        push(p);
        int m=(l+r)>>1;
        if(idx<=m) return point_query(p<<1, l, m, idx);
        else return point_query(p<<1|1, m+1, r, idx);
    }
    int point_query(int idx){ return point_query(1,0,n,idx); }    
};
    
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegTree seg(n);
        unordered_map<int,int>lastPos;
        int ret = 0;
        for (int r = 1; r <= n; r++) {
            int v = nums[r-1];
            int sign = (v%2==0)?1:-1;
            int prev = 0;
            auto iter = lastPos.find(v);
            if (iter!=lastPos.end()) 
                prev = iter->second;
            if (prev==0) {
                seg.range_add(r, n, sign);
            } else {
                if (prev<=r-1)
                    seg.range_add(prev, r-1, -sign);
            }
            lastPos[v] = r;
            int cur = seg.point_query(r);
            int idx = seg.find_first_equal(0,r-1,cur);
            if (idx!=-1)
                ret = max(ret, r-idx);
        }
        return ret;
    }
};
