class Solution {
public:
    int maxSubArray(vector<int>& nums) {

       int maxSum = INT_MIN;
       int sum = 0;

       int right = 0;

       for (right=0; right<nums.size(); right++){

         if (sum<0) sum = 0;
         sum += nums[right];

         if (maxSum<sum) maxSum = sum;

       }

       return maxSum;
    }
};
