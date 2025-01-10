// [1,2,4,0,0,0]
// i=3 z = 3
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for(int i=0;i<nums.size();i++){
            if(!nums[i])zeros++;
            else{
                nums[i-zeros]=nums[i];
            }
        }
        
        for(int i=nums.size()-zeros;i<nums.size();i++)nums[i] = 0;
    }
};
