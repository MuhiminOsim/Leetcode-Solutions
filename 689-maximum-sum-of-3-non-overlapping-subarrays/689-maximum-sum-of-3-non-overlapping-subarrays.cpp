class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        for(int i = 0; i < n; i++) {
            prefixSum[i] = nums[i];
            if(i != 0) prefixSum[i] += prefixSum[i - 1];
        }
        
        vector<int> leftMax(n, 0), rightMax(n, 0);
        
        leftMax[k - 1] = 0;
        rightMax[n - k] = n - k;
        
        for(int i = k; i < n; i++) {
            int prevIdx = leftMax[i - 1];
            long long prevMax = prefixSum[prevIdx + k - 1] - (prevIdx > 0 ? prefixSum[prevIdx - 1] : 0);
            if(prevMax < (prefixSum[i] - prefixSum[i - k])) {
                leftMax[i] = i - k + 1;
            }
            else leftMax[i] = leftMax[i - 1];
        }
        
        for(int i = n - k - 1; i >= 0; i--) {
            int prevIdx = rightMax[i + 1];
            long long prevMax = prefixSum[prevIdx + k - 1] - (prevIdx > 0 ? prefixSum[prevIdx - 1] : 0);
            if(prevMax <= (prefixSum[i + k - 1] - (i > 0? prefixSum[i - 1] : 0))) {
                rightMax[i] = i;
            }
            else rightMax[i] = rightMax[i + 1];
        }
        
        long long maxSum = 0;
        vector<int> indices;
        for(int i = 2 * k - 1; i + k < n; i++) {
            long long curMax = prefixSum[i] - prefixSum[i - k];
            long long leftSum = prefixSum[leftMax[i - k] + k - 1] - (leftMax[i - k] > 0 ? prefixSum[leftMax[i - k] - 1] : 0);
            long long rightSum = prefixSum[rightMax[i + 1] + k - 1] - (rightMax[i + 1] > 0 ? prefixSum[rightMax[i + 1] - 1] : 0);
            curMax += (leftSum + rightSum);
            if(curMax > maxSum) {
                maxSum = curMax;
                indices = {leftMax[i - k], i - k + 1, rightMax[i + 1]};
            }
        }
        
        return indices;
    }
};