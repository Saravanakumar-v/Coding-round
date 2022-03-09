#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<random>

using namespace std;

// Function declaration
void print_area(vector<vector<int>> &area,int &row,int &column);
void count_neighbour(vector<vector<int>> &area,int &row,int &column);
int traverse_neighbour(vector<vector<int>> &area,int &row,int &column);

// function definition
void print_area(vector<vector<int>> &area,int &row,int &column) {
    for(int i=0;i< row;i++) {
        for(int j=0;j< column;j++) {
            cout<<area[i][j]<<" ";
        }
        cout<<endl;
    }
}

void count_neighbour(vector<vector<int>> &area,int &row,int &column) {
    int count = 0;
    for(int i=0;i< row;i++) {
        for(int j=0;j< column;j++) {
            if(area[i][j] == 1) {
                count = max(count,traverse_neighbour(area,i,j));
            }
        }
    }
    cout<<"maximum-nearest-neighbour: "<<count;
}

int traverse_neighbour(vector<vector<int>> &area,int &row,int &column) {
    int neighbour = 1;
    int m = area.size();
    int n = area[0].size();

    area[row][column] = 0;
    vector<int> direction({-1,0,1,0,-1}); // for four direction up,down,left,right
    
    for(int i=0;i< direction.size();i++) {
        int rw = row+direction[i];
        int col = column+direction[i+1];

        if(rw >= 0 && rw < m && col >= 0 && col < n && area[rw][col] == 1) {
            neighbour = neighbour + traverse_neighbour(area, rw, col);
        }
    }
    return neighbour;
}

int main()
{
    vector<vector<int>> area;

    int row,column;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter column: ";
    cin>>column;

    for(int i=0;i< row;i++) {
        vector<int> r1;
        for(int j=0;j< column;j++) {
            int value = rand() %2 ;     // Enter random 0 and 1 as input into area grid
            r1.push_back(value);
        }
        area.push_back(r1);
    }

    print_area(area,row,column);
    count_neighbour(area,row,column);
    return 0;
}
