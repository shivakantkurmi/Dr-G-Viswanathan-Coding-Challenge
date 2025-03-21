/*
69. Sqrt(x)
Hint
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/

//Solution 1 : by iteration from 1 to sqrt(n) (i*i<=value)
class Solution {
public:
    int mySqrt(int x) {
        long i=0;
        while(i*i<=x)i++;
        return i-1;
    }
};

//Solution 2 : by using binary search(as integers are sorted )
class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x,ans;
        while(l<=h){
            int m = (l+h)/2;
            long long  m_sq = (long long)m*m;
            if (m_sq == x)  
                return m;
            else if (m_sq < x){  
                ans = m;
                l = m + 1;
            }
            else       
                h = m-1;
        }
        return ans;
    }
};
