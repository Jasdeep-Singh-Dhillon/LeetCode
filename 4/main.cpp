#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int i = 0;
          int j = 0; 
          vector<int> combined;
          while (i < nums1.size() && j < nums2.size()) {       
               if(nums1[i] < nums2[j] ) {
                    combined.push_back(nums1[i]);
                    i++;
               } else { 
                    combined.push_back(nums2[j]);
                    j++;
               }
          }
          if(i >= nums1.size()) {
               for(j; j < nums2.size(); j++) {
                    combined.push_back(nums2[j]);
               }
          }
          if(j >= nums2.size()) {
               for(i; i < nums1.size(); i++) {
                    combined.push_back(nums1[i]);
               }
          }

          int size = combined.size();
          if(size % 2 == 0) {
               size = (size-1)/2;
               return ((combined[size] + combined[size+1])/2.0);
          } else {
               return combined[size/2];
          }
    }

    
};

int main() {
     Solution solution;
     
     vector<int> nums1_1{1,3};
     vector<int> nums1_2{2};
     cout << "Expected Output: " << "2.00000" << endl;
     cout << "Your Output:     " << solution.findMedianSortedArrays(nums1_1, nums1_2) << endl;
     
     vector<int> nums2_1{1,2};
     vector<int> nums2_2{3,4};
     cout << "Expected Output: " << "2.50000" << endl;
     cout << "Your Output:     " << solution.findMedianSortedArrays(nums2_1, nums2_2) << endl;
     
}