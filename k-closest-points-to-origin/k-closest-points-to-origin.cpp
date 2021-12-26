class Solution {
public:
    
    int quickselect(vector<int> array, int k) {
      int startIdx = 0, endIdx = array.size() - 1;

        while(true) {
            int pivotIdx = startIdx;
            int leftIdx = startIdx + 1;
            int rightIdx = endIdx;
            while(leftIdx <= rightIdx) {
                if(array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]) {
                    swap(array[leftIdx], array[rightIdx]);
                }
                if(array[leftIdx] <= array[pivotIdx]) leftIdx++;
                if(array[rightIdx] >= array[pivotIdx]) rightIdx--;
            }

            swap(array[pivotIdx], array[rightIdx]);
            if(rightIdx == k - 1) return array[rightIdx];
            else if(rightIdx < k - 1) startIdx = rightIdx + 1;
            else endIdx = rightIdx - 1;
        }

      return -1;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> distances;
        
        for(auto point : points) {
            distances.push_back(point[0] * point[0] + point[1] * point[1]);
        }
        
        int distance = quickselect(distances, k);
        
        vector<vector<int>> kClosestPoints;
        
        for(vector<int> point : points) {
            int curDistance = point[0] * point[0] + point[1] * point[1];
            if(curDistance <= distance) {
                kClosestPoints.push_back(point);
            }
        }
        
        return kClosestPoints;
    }
};