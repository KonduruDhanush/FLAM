#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity){
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()){
            return -1;
        }
        auto it = cache[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();
        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dll.erase(cache[key]);
        }
        else if (dll.size() == cap) {
            auto last = dll.back();
            cache.erase(last.first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    return 0;
}
