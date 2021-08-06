#include <QCoreApplication>
#include <iostream>
#include <queue>

class Solution{
public:
    int numIslands(std::vector<std::vector<char>>& grid){
        std::queue<int> landPoint;
        int m = grid[0].size();
        int n = grid.size();
        int numSize[m*n];
        std::fill(numSize, numSize+(m*n), 0);
        int numLands = 0;
        int numWater = 0;
        int i = 0;
        int j = 0;
        int iValue = 0;
        int colValue = 0;
        int rowValue = 0;
        while(i < n - 1 || j < m - 1 )
        {
            landPoint.push(i*m+j);
            if(grid[i][j] == '1')
                numLands++;
            else
                numWater++;

            while(landPoint.empty() != true)
            {
                iValue = landPoint.front();
                landPoint.pop();
                colValue = iValue / m;
                rowValue = iValue % m;
                i = colValue;
                j = rowValue;
                int temIvalue = 0;
                if(j < m - 1)
                    if(grid[i][j + 1] == grid[colValue][rowValue])
                    {
                        temIvalue = i*m+(j + 1);
                        if(numSize[temIvalue] == 0)
                        {
                            landPoint.push(temIvalue);
                            numSize[temIvalue] = 1;
                        }
                    }
                if(j > 0)
                    if(grid[i][j - 1] == grid[colValue][rowValue])
                    {
                        temIvalue = i*m+(j - 1);
                        if(numSize[temIvalue] == 0)
                        {
                            landPoint.push(temIvalue);
                            numSize[temIvalue] = 1;
                        }
                    }
                if(i < n - 1)
                    if(grid[i + 1][j] == grid[colValue][rowValue])
                    {
                        temIvalue = (i + 1)*m+j;
                        if(numSize[temIvalue] == 0)
                        {
                            landPoint.push(temIvalue);
                            numSize[temIvalue] = 1;
                        }
                    }
                if(i > 0)
                    if(grid[i - 1][j] == grid[colValue][rowValue])
                    {
                        temIvalue = (i - 1)*m+j;
                        if(numSize[temIvalue] == 0)
                        {
                            landPoint.push(temIvalue);
                            numSize[temIvalue] = 1;
                        }
                    }
            }

            int ii = 1;
//            int jj = 1;
            for(;ii< m*n - 1; ii++ )
            {
                if(numSize[ii] == 0)
                {
                    iValue = ii;
//                    jj++;
                    i = iValue / m;
                    j = iValue % m;
                    numSize[ii] = 1;
                    break;
                }

            }
           if(ii == m*n - 1)
           {
               iValue = ii;
               i = iValue / m;
               j = iValue % m;
               numSize[ii] = 1;
               break;
           }

        }
        if(i == n - 1 && j == m - 1)
        {
           if(grid[i][j] == '1')
           {
               if(i - 1 >= 0 && j - 1 >= 0)
               {
                    if(grid[i][j] != grid[i][j - 1] && grid[i][j] != grid[i - 1][j])
                        numLands++;
               }
               if(i - 1 >= 0 && j - 1 < 0)
               {
                   if(grid[i][j] != grid[i - 1][j])
                       numLands++;
               }
               if(i - 1 < 0 && j - 1 >= 0)
               {
                   if(grid[i][j] != grid[i][j - 1])
                       numLands++;
               }
               if(i - 1 < 0 && j - 1 < 0)
               {
                   numLands++;
               }
           }
        }
        return numLands;
    };
//private:
    // vector<vector<char>> grid;

};
//[["1","1","0","0","0"],
//    ["1","1","0","0","0"],
//    ["0","0","1","0","0"],
//    ["0","0","0","1","1"]]
int main()
{
//    std::vector<std::vector<char>> grid = {{'1','1','1','1','0'},
//                                           {'1','1','0','1','0'},
//                                           {'1','1','0','0','0'},
//                                           {'0','0','0','0','0'}};
//    std::vector<std::vector<char>> grid = {{'1','1','0','0','0'},
//                                           {'1','1','0','0','0'},
//                                           {'0','0','1','0','0'},
//                                           {'0','0','0','1','1'}};
//    std::vector<std::vector<char>> grid = {{'1'}};
//    [["0","0","0","0","0","0","1"]]
//    std::vector<std::vector<char>> grid ={{'0', '0', '0', '0', '0', '0', '1'}};
//    std::vector<std::vector<char>> grid = {{'1', '0', '1'},{'0', '1', '0'},{'1', '0','1'}};
     std::vector<std::vector<char>> grid = {{'1', '1', '1'},
                                            {'0', '1', '0'},
                                            {'1', '1','1'}};
    std::cout<<"The number of land is: \n";
    Solution a;
    std::cout<<"we made an object. \n";
    std::cout<<a.numIslands(grid)<<'\n';
    return 0;
}
