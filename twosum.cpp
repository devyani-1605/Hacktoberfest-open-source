#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        // Traverse the given vector
        for(int i = 0; i < nums.size(); i++) {
            // Search for the element just greater than the current element
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
            
            // If the element is found, then insert both the indices in the result vector
            if(it != nums.end() && *it == target - nums[i]) {
                result.push_back(i);
                result.push_back(it - nums.begin());
                break;
            }
        }
        
        // Return the result vector
        return result;
    }
};

int main() {
    Solution solution;
    int n, target;
    
    // Input number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the array elements
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input the target value
    cout << "Enter the target value: ";
    cin >> target;

    // Call the twoSum function
    vector<int> result = solution.twoSum(nums, target);

    // Output the result
    if (!result.empty()) {
        cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers found that add up to the target." << endl;
    }

    return 0;
}
