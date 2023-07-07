
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        solve(grid);
        return true; 
    }
    
    bool solve(int grid[N][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    
                    for(int k=1;k<=N;k++){
                    if(isValid(grid,i,j,k)){
                        grid[i][j]=k;
                        
                        if(solve(grid))return true;
                        else
                        grid[i][j]=0;
                    }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int grid[N][N],int row,int col,int e){
        for(int i=0;i<N;i++){
            //row check
            if(grid[row][i]==e)return false;
            //column check
            if(grid[i][col]==e)return false;
            //box(submatrix) check
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==e)return false;
            
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};


int main() {
    Solution ob;
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (ob.SolveSudoku(grid) == true) {
        // Sudoku solved successfully
        cout<<"Suceess, \nSolved Sudoku is \n";
        ob.printGrid(grid);
    } else {
        // Unable to solve Sudoku
        cout<<"Not Suceess";
    }

    std::cout << std::endl;

    return 0;
}