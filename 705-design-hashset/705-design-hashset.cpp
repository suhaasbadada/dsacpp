const int MAX=1e6+1;
class MyHashSet {
public:
    vector<bool>elements;
    MyHashSet() {
        elements.resize(MAX,false);
    }
    
    void add(int key) {
        elements[key]=true;
    }
    
    void remove(int key) {
        elements[key]=false;
    }
    
    bool contains(int key) {
        return elements[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */