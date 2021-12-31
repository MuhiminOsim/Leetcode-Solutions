class Solution {
public:
    int findKthLargest(vector<int>& array, int k) {
        int startIdx = 0, endIdx = array.size() - 1;
	
        while(true) {
            int pivotIdx = startIdx;
            int leftIdx = startIdx + 1;
            int rightIdx = endIdx;
            while(leftIdx <= rightIdx) {
                if(array[leftIdx] < array[pivotIdx] && array[rightIdx] > array[pivotIdx]) {
                    swap(array[leftIdx], array[rightIdx]);
                }
                if(array[leftIdx] >= array[pivotIdx]) leftIdx++;
                if(array[rightIdx] <= array[pivotIdx]) rightIdx--;
            }

            swap(array[pivotIdx], array[rightIdx]);
            if(rightIdx == k - 1) return array[rightIdx];
            else if(rightIdx < k - 1) startIdx = rightIdx + 1;
            else endIdx = rightIdx - 1;
        }

        return -1;
    }
};

// average time complexity - O(n)
// worst time complexity - O(n^2)