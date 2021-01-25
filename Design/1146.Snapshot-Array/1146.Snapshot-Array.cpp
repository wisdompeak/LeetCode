class SnapshotArray {        
    int vals[50000];
    vector<vector<pair<int,int>>>snaps;
    unordered_set<int>changed;
    int snapId;
public:
    SnapshotArray(int length) 
    {    
        snapId = 0;
        snaps.resize(length);
        for (int i=0; i<length; i++)
            snaps[i].push_back({-1,0});
    }
    
    void set(int index, int val) 
    {
        vals[index] = val;
        changed.insert(index);
    }
    
    int snap() 
    {
        for (int index: changed)
        {
            snaps[index].push_back({snapId, vals[index]});
        }
        snapId++;
        changed.clear();
        return snapId-1;
    }
    
    int get(int index, int snap_id) 
    {
        auto iter = upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id, INT_MAX));
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
