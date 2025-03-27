/*
Common in 3 Sorted Arrays
Difficulty: EasyAccuracy: 22.16%Submissions: 416K+Points: 2
Given three sorted arrays in non-decreasing order, print all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array. In this case, the output will be -1.

Note: can you handle the duplicates without using any additional Data Structure?

Examples :
Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.
*/

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        vector<int> ans;
        int i=0,j=0,k=0,n=arr1.size(),m=arr2.size(),p=arr3.size();
        int last=0;
        while(i<n&&j<m&&k<p){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                if(arr1[i]!=last){
                    last=arr1[i];
                    ans.push_back(arr1[i]);
                }
                i++,j++,k++;
            }
            else if (arr1[i] < arr2[j]) i++; 
            else if (arr2[j] < arr3[k]) j++;
            else k++;
        }
        return ans;
    }
};
