/*
Pascal Triangle
Difficulty: MediumAccuracy: 23.68%Submissions: 122K+Points: 4Average Time: 20m
Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

File:PascalTriangleAnimated2.gif

Examples:

Input: n = 4
Output: [1, 3, 3, 1]
Explanation: 4th row of pascal's triangle is [1, 3, 3, 1].
Input: n = 5
Output: [1, 4, 6, 4, 1]
Explanation: 5th row of pascal's triangle is [1, 4, 6, 4, 1].
Input: n = 1
Output: [1]
Explanation: 1st row of pascal's triangle is [1].
Constraints:
1 ≤ n ≤ 20

*/


class Solution {
  public:
    long long factorial(int n){
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
        }
        
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1) return {1};
        if(n==2) return {1, 1};
        
        vector<int> A;
        A.push_back(1);
        for(int i=1;i<n;i++){
          long long x;
          x=factorial(n-1)/(factorial(i)*factorial(n-1-i));
          A.push_back(x);
         }
         return A;
    }
};
