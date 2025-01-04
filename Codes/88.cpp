class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m-1;i>=0;i--){
            nums1[i+n] = nums1[i];
        }

        int idx1 = n, idx2 = 0;
        for(int i=0;i<m+n;i++){
            if( (idx2<n && idx1<m+n && nums1[idx1]<nums2[idx2]) || idx2 == n){
                nums1[i] = nums1[idx1++];
            } else {
                nums1[i] = nums2[idx2++];
            } 
        }
    }
};
