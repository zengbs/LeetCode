// time: O(N)
// space: O(N)

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

      int length = nums.size();

      std::vector<int> prefix(length);
      std::vector<int> suffix(length);
      std::vector<int> answer(length);

      prefix[0]        = 1;
      suffix[length-1] = 1;

      for ( int i=1; i<length; i++ ){
         prefix[i] = prefix[i-1] * nums[i-1];
         suffix[length-i-1] = suffix[length-i] * nums[length-i];
      }


      for (int i=0; i<length; i++){
         answer[i] = prefix[i]*suffix[i];
      }

      return answer;

    }
};

// time: O(N)
// space: O(1)

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

      int length = nums.size();

      std::vector<int> prefix(length);
      std::vector<int> suffix(length);
      std::vector<int> answer(length);

      prefix[0]        = 1;
      suffix[length-1] = 1;

      for ( int i=1; i<length; i++ ){
         prefix[i] = prefix[i-1] * nums[i-1];
         suffix[length-i-1] = suffix[length-i] * nums[length-i];
      }


      for (int i=0; i<length; i++){
         answer[i] = prefix[i]*suffix[i];
      }

      return answer;

    }
};
