// Source : https://leetcode.com/problems/two-sum/description/
// Author : Andy Yuan
// Date   : 2018-05-08

/********************************************************************************** 
* 
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

* You may assume that each input would have exactly one solution, and you may not use the same element twice.

* Example:

* Given nums = [2, 7, 11, 15], target = 9,

* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
* 
*               
**********************************************************************************/

class Solution {
public:
    // First, sort the array. Next, find the result.
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexs;
        vector<int>::iterator it;
        
        std::sort (nums.begin(), nums.end());
        
        int index = 0;
        for (it = nums.begin(); it < nums.end(); ++it) {
            if (*it >= target) break;
            index++;
        }

        int i = 0;
        int j = 0;
        bool find = false;
        for (; i < index; ++i) {
            for (j = i + 1; j < index; ++j) {
                if (nums[i] + nums[j] == target) {

                    indexs.push_back(i);
                    indexs.push_back(j);

                    find = true;
                    break;
                }
            }
        if (find) break;
        }
        
        return indexs;
    }

    // Implementation with hashmap
    vector<int> twoSum_hashmap(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> indexs;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end()) {
                indexs.push_back(m[nums[i]]);
                indexs.push_back(i);
                break;
            }else{
                // If there are duplication numbers in the array, we can throw away this number.
                if (m.find(target - nums[i]) == m.end())
                  m[target - nums[i]] = i;
            }
        }

        return indexs;

    }

};
