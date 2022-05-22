// https://leetcode.com/problems/find-the-duplicate-number/description/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// brute force approach
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return 0;
    }
};
// using map
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto x : nums)
        {
            m[x]++;
        }
        for (auto x : m)
        {
            if (x.second > 1)
                return x.first;
        }
        return 0;
    }
};
// Optimised approach using LL Loop Slow Fast Concept
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//solution refrence by 
//https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/