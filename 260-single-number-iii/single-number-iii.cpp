class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall = 0;
        for(int i = 0; i<nums.size(); i++){
            xorall = xorall ^ nums[i];
        }
        long long bit = xorall & (-xorall);
        int a = 0; int b = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] & bit){
                a = a^ nums[i];
            }else{
                b = b^nums[i];
            }
        }
        return {a,b};
    }
};