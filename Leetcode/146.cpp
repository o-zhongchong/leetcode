/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class CacheNode {
public:
    CacheNode(int k=0, int v=0) {
        pre = next = nullptr;
        key = k;
        val = v;
    }
    ~CacheNode();
public:
    CacheNode *pre;
    CacheNode *next;
    int key;
    int val;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        mMaxLength = capacity;
        mLength = 0;
        head = new CacheNode();
        tail = new CacheNode();
        head->next = tail;
        tail->pre = head;
    }
    int get(int key) {
        int value = -1;
        if(mMap.count(key)) {
            CacheNode *node = mMap[key];
            value = node->val;
            deleteCacheNode(node);
            insertCacheNode(head, node);
        }
        return value;
    }
    void put(int key, int value) {
        if(mMap.count(key)) {
            CacheNode *node = mMap[key];
            node->val = value;
            deleteCacheNode(node);
            insertCacheNode(head, node);
        } else {
            CacheNode *node = new CacheNode(key, value);
            mMap[node->key] = node;
            insertCacheNode(head, node);
            while(mLength > mMaxLength) {
                mMap.erase(tail->pre->key);
                deleteCacheNode(tail->pre);
            }
        }
    }
private:
    void deleteCacheNode(CacheNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->pre = node->next = nullptr;
        --mLength;
    }
    void insertCacheNode(CacheNode* head, CacheNode* node) {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
        ++mLength;
    }
private:
    int mMaxLength;
    int mLength;
    CacheNode *head;
    CacheNode *tail;
    unordered_map<int,CacheNode*> mMap;
};
