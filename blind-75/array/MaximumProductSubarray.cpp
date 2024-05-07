// https://www.geeksforgeeks.org/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

    int ans=INT_MIN;
    int product=1;

    for(int i=0;i<nums.size();i++){
      product*=nums[i];
      ans=max(ans,product);
      if(nums[i]==0){product=1;}
    }

    product=1;

    for(int i=nums.size()-1;i>=0;i--){
      product*=nums[i];
      ans=max(ans,product);
      if(nums[i]==0){product=1;}
    }

      return ans;
    }
};
