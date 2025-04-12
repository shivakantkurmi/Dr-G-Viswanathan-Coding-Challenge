/*
Flood fill Algorithm
Difficulty: MediumAccuracy: 41.11%Submissions: 136K+Points: 4Average Time: 15m
You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

Examples:

Input: image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2

Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]

Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].
*/

class Solution {
  public:
    void dfs(int sr,int sc,vector<vector<int>>& image, int newColor,int m,int n,int col){
      
     image[sr][sc]=newColor;
     vector<int> dx={1,0,-1,0};
     vector<int> dy={0,-1,0,1};
     for(int i=0;i<4;i++){
         int r=sr+dx[i];
         int c=sc+dy[i];
         if(r>=0 and r<m and c>=0 and c<n and image[r][c]==col){
             dfs(r,c,image,newColor,m,n,col);
         }
     }
      
      
    }
  
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int m=image.size();
        int n=image[0].size();
        int col=image[sr][sc];
        if (col == newColor) return image;

        dfs(sr,sc,image,newColor,m,n,col);
        return image;
    }
};
