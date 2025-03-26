/*
Frequencies in a Limited Array
Difficulty: EasyAccuracy: 27.64%Submissions: 356K+Points: 2Average Time: 10m
You are given an array arr[] containing positive integers. The elements in the array arr[] range from 1 to n (where n is the size of the array), and some numbers may be repeated or absent.
Your task is to count the frequency of all numbers in the range 1 to n and return an array of size n such that result[i] represents the frequency of the number i (1-based indexing).
*/

class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        int n=arr.size();
        for (int i = 0; i < n; i++) {
            arr[i] -= 1;
        }

    // Step 2: Use index-based marking
        for (int i = 0; i < n; i++) {
            if (arr[i] % (n + 1) < n) {  // Ignore out-of-range values
                arr[arr[i] % (n + 1)] += (n + 1);
            }
        }

        // Step 3: Extract frequencies in-place
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / (n + 1); // Store final frequencies in arr itself
        }
        return arr;
    }
};
