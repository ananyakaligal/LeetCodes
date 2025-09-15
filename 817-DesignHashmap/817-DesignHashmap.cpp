// Last updated: 9/16/2025, 12:05:00 AM
class MyHashMap {
private:
    static const int SIZE = 10000;
    vector<vector<pair<int, int>>> map;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        map.resize(SIZE);
    }

    void put(int key, int value) {
        int index = hash(key);
        for (auto& pair : map[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        map[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash(key);
        for (auto& pair : map[index]) {
            if (pair.first == key) return pair.second;
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        auto& bucket = map[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */