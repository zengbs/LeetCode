class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

       std::unordered_set<int> uset;

       for( int& element : nums ){

          auto itr = uset.find(element);

          if ( itr != uset.end() ){
             return true;
          }

          uset.insert(element);
       }
       return false;
    }
};
