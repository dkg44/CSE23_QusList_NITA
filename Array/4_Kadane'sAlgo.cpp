//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){

        int msf =INT_MIN;
        int meh =0;
        
        for(int i=0;i<n;i++)
        {
            meh = meh + arr[i];
            if(meh<arr[i])
            meh = arr[i];
            if(msf<meh)
            msf = meh;
            
        }
        return msf;
    }
};