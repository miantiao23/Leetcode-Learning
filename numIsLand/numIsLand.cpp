#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Solution{
public:
	int numIslands(vector<vector<char>>& grid){
		// std::cout << "grid size m: "<<grid.length()<<'\n'; 
		cout << "grid size m: "<<grid.size()<<'\n';
		cout << "grid size n: "<<grid[0].size() <<'\n';
		queue<char>* landPoint;
		int i = 0;
		int j = 0;
		for(; i < grid.size(); i++)
		{
			for(; j < grid[0].size(); j++)
			{
				if(grid[i][j] != '0')
					break;
			}
			cout<<"The first point position is:"<<'('<<i<<','<<j<<')'<<'\n';
			if(grid[i][j] != '0')
				break;
		}
		cout<<"The first point position is:"<<'('<<i<<','<<j<<')'<<'\n';




	}
// private:
	// vector<vector<char>> grid;
};

int main()
{
	vector<vector<char>> grid = {{'0','0','1','1','0'},
							    {'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'}};
	// cout << "grid size m: "<<grid.size()<<'\n';
	// cout << "grid size n: "<<grid[0].size()<<'\n';
	Solution a;
	a.numIslands(grid);
	// cout << grid<<'\n';

	return 0;
}