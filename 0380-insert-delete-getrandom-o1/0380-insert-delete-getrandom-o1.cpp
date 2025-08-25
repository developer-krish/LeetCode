class RandomizedSet {
public:
    vector<int> nums; // store elements
    unordered_map<int, int> mpp; // maps value -> index in nums
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mpp.count(val)) return false;
        nums.push_back(val);
        mpp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int ind = mpp[val];
        int last = nums.back();

        nums[ind] = last;
        mpp[last] = ind;
        nums.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand() % nums.size();
        return nums[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */