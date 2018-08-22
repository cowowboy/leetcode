class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int,int> ret;
        for(int i=0;i<nums.size();i++) {
            int pair = target - nums[i];
            //find this 
            if(ret.count(pair) > 0){
                result[0] = ret[pair];
                result[1] = i;
                return result;
            }
            //like python dict feed values to key.
            ret[nums[i]] = i;  
        }
    }
};
