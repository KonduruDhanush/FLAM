#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    static const int size = 10007;
    vector<pair<int, int>> table[size];

    int hash_func(int key) {
        return key % size;
    }

public:
    void put(int key, int value) {
        int index = hash_func(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash_func(key);
        for (auto &g : table[index]) {
            if (g.first == key) return g.second;
        }
        return -1;
    }

    void remove(int key) {
        int index = hash_func(key);
        auto &bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap map;
    map.put(1, 10);
    map.put(2, 20);
    cout << map.get(1) << endl;
    cout << map.get(3) << endl;
    map.put(2, 30);
    cout << map.get(2) << endl;
    map.remove(2);
    cout << map.get(2) << endl;
    return 0;
}
