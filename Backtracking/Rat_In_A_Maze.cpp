#include<iostream>
using namespace std;
vector<vector<bool>> maze;
void printPaths(int cr, int cc, int er, int ec, string s){
    if(cr == er && cc == ec){ // right destination
        cout<<s<<endl;
        return;
    }
    if(cr < 0 or cc < 0 or cr > er or cc > ec or maze[cr][cc]==true) return; // out of maze
    maze[cr][cc] = true;
    printPaths(cr,cc+1,er,ec,s+"R"); // right
    printPaths(cr+1,cc,er,ec,s+"D"); // down
    printPaths(cr,cc-1,er,ec,s+"L"); // left
    printPaths(cr-1,cc,er,ec,s+"U"); // up
    maze[cr][cc] = false; // backtracking
}
int main(){
    int m = 3, n = 3;
    maze.resize(m,vector<bool>(n,false));
    printPaths(0,0,m-1,n-1,"");
}
