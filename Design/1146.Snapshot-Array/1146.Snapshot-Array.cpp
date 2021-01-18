class SnapshotArray {
    vector<int>arr;
    vector<vector<pair<int,int>>>snaps;
    unordered_set<int>changed;
    int count;
public:
    SnapshotArray(int length) 
    {
        arr.resize(length);
        snaps.resize(length);
        for (int i=0; i<length; i++)
        {
            arr[i] = 0;
            snaps[i].push_back({-1,0});
        }
        count = 0;
    }
    
    void set(int index, int val) 
    {
        arr[index] = val;
        changed.insert(index);
    }
    
    int snap() 
    {
        for (auto idx: changed)
        {
            snaps[idx].push_back({count,arr[idx]});
        }
        count++;
        changed.clear();
        return count-1;
    }
    
    int get(int index, int snap_id) 
    {
        auto iter = upper_bound(snaps[index].begin(),snaps[index].end(),make_pair(snap_id,INT_MAX));
        iter = prev(iter,1);
        return iter->second;        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
