class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_map<int, int> mpp;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++)
        {
            mpp[arr[i]] = i;
        }
        for(int i = 0 ; i < n ; i++)
        {
            int cal = arr[i] * 2;
            if(mpp.find(cal) != mpp.end() && mpp[cal] != i)
               return true;
        }
        return false;
    }
};