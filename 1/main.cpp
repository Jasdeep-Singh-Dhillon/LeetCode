#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                if( (nums[i] + nums[j]) == target && i!=j) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

string vtoString(vector<int> vect) {
    string str = "[";
    for(int i=0; i<vect.size(); i++) {
        if(i!=0) {
            str.append(",");
        }
        str = str + to_string(vect[i]);
    }
    str.append("]");
    return str;
}

int main() {
    Solution solution;

    vector<int> nums1 {2,7,11,15};
    int target1 = 9;
    vector<int> out1 {0,1};
    cout << "Input: " << vtoString(nums1) << " " << "Target: " << target1 << endl;
    cout << "Your Solution: " << vtoString(solution.twoSum(nums1, target1)) << endl;
    cout << "Desired Output: " << vtoString(out1) << endl << endl;

    vector<int> nums2 {3,2,4};
    int target2 = 6;
    vector<int> out2 {1,2};
    cout << "Input: " << vtoString(nums2) << " " << "Target: " << target2 << endl;
    cout << "Your Solution: " << vtoString(solution.twoSum(nums2, target2)) << endl;
    cout << "Desired Output: " << vtoString(out2) << endl << endl;

    vector<int> nums3 {3,3};
    int target3 = 6;
    vector<int> out3 {0,1};
    cout << "Input: " << vtoString(nums3) << " " << "Target: " << target3 << endl;
    cout << "Your Solution: " << vtoString(solution.twoSum(nums3, target3)) << endl;
    cout << "Desired Output: " << vtoString(out3) << endl << endl;
}
