class FileSystem {
public:
    FileSystem() {
        
    }
    
    bool create(string path, int value) {
        if(path.empty())
            return false;
        
        if(path[0] != '/')
            return false;
        
        auto search = fs.find(path);
        if( search != fs.end() )
            return false;
        
        int pos = path.rfind("/");
        if( pos != 0 )
        {
            string dir = path.substr(0,pos);
            search = fs.find(dir);
            if( search == fs.end() )
                return false;
        }
        
        fs[path] = value;
        return true;
    }
    
    int get(string path) {
        auto search = fs.find(path);
        if( search != fs.end() )
            return search->second;
        return -1;
    }
protected:
    unordered_map<string,int> fs;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */