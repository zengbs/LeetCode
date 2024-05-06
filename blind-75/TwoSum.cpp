class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       std::unordered_map<int,int> umap;

       std::vector<int> ans = {1,1};

       int index = 0;

       for ( int& element : nums ){

          auto i = umap.find(target-element);

          if ( i != umap.end() ){
             ans[0] = index;
             ans[1] = i->second;
             return ans;
          }

          umap.insert({element,index});

          index++;
       }

      return ans;
    }
};
