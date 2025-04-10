/*
Smallest greater elements in whole array
Difficulty: EasyAccuracy: 39.0%Submissions: 25K+Points: 2
Given an array A of N length. We need to calculate the next smallest greater element for each element in a given array. If the next greater element is not available in a given array then we need to fill -10000000 at that index place.

Example 1:

Input : arr[] = {13, 6, 7, 12}
Output : _ 7 12 13 
Explanation:
Here, at index 0, 13 is the greatest value 
in given array and no other array element 
is greater from 13. So at index 0 we fill 
'-10000000'.
*/

int* greaterElement(int arr[], int n)
{
    vector<int> v;
    unordered_map<int,int>m;
    
    for(int i=0;i<n;i++)
    v.push_back(arr[i]);
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<n-1;i++)
    m[v[i]] = v[i+1];
    
    m[v[n-1]] = -10000000;
    
    for(int i=0;i<n;i++)
    arr[i] = m[arr[i]];
    
    return arr;
}
