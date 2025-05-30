/*
832. Flipping an Image
Solved
Easy
Topics
premium lock icon
Companies
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
*/

//Link : https://leetcode.com/problems/flipping-an-image/description/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (auto& row : image) {
            int left = 0, right = n - 1;
            while (left <= right) {
                if (left == right) {
                    row[left] ^= 1; 
                } else {
                    int temp = row[left] ^ 1;
                    row[left] = row[right] ^ 1;
                    row[right] = temp;
                }
                ++left;
                --right;
            }
        }

        return image;
    }
};
