class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> newArray;
        
        for(int x : nums) if(x < pivot) newArray.push_back(x);
        for(int x : nums) if(x == pivot) newArray.push_back(x);
        for(int x : nums) if(x > pivot) newArray.push_back(x);
        
        return newArray;
    }
};