//https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force solution
        vector<int>vect;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i]+nums[j]==target){
                    vect.push_back(i);
                    vect.push_back(j);
                    break;
                }
            }
        }
        return vect;
    }
};

//optimized approach
// using map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i]) !=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);//index of the value that is prasent in hash table already
                
                ans.push_back(i);//corrent itr element index that matched with target
                return ans;//return the desired ans 
            }
            mp[nums[i]]=i;//for insert trhe index in hash table
        }
        return ans;//for empty ans return
    }
};
