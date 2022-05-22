//https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// using sorting
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

// using sort and Stack
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n= intervals.size();
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> s;
        s.push({intervals[0][0] , intervals[0][1]});

        for(int i=1; i<n; i++){
            int st1 = s.top().first;
            int end1 = s.top().second;
            int st2 = intervals[i][0];
            int end2 = intervals[i][1];
            
            if(end1<st2){
                s.push({st2,end2}); 
            }
            else{ //[1,3] [2,6]
                s.pop(); 
                end1 = max(end1, end2); // max(3,6) = 6;
                s.push({st1,end1});
            }
        }
       // return s;
        while(!s.empty()){
            res.push_back({s.top().first, s.top().second});
            s.pop();               
        }
        return res;
    }
};