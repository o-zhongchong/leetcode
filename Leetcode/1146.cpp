class SnapshotArray {
public:
    SnapshotArray(int length) {
        snapshot_id = 0;
        for(int i=0; i<length;++i)
        {
            map<int,int> val_map;
            val_map.insert( make_pair(snapshot_id,0) );
            snapshot_array.push_back(val_map);
        }
    }
    
    ~SnapshotArray()
    {
        snapshot_array.clear();
    }
    
    void set(int index, int val) {
        if( index >= 0 && index < snapshot_array.size() )
        {
            snapshot_array[index][snapshot_id] = val;
        }
    }
    
    int snap() {
        ++snapshot_id;
        return snapshot_id - 1;
    }
    
    int get(int index, int snap_id) {
        if( index >= 0 && index < snapshot_array.size() )
        {
            map<int,int> &val_map = snapshot_array[index];
            auto search = val_map.find(snap_id);
            while( search == val_map.end() )
            {
                --snap_id;
                search = val_map.find(snap_id);
            }
            return search->second;
        }
        return -1;
    }
private:
    int snapshot_id;
    vector<map<int,int>> snapshot_array;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */