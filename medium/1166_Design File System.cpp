// design
// string
// 240ms, beats 92.65%

// Main idea:
// Use hash table to store path and its value.

class FileSystem {
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        string parentPath = path.substr(0, path.rfind('/'));
        if(!parentPath.empty() && filePath.count(parentPath) == 0) return false;
        return filePath.emplace(path, value).second;
    }
    
    int get(string path) {
        if(filePath.count(path) == 0) return -1;
        return filePath[path];
    }
private:
    unordered_map<string, int> filePath;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */