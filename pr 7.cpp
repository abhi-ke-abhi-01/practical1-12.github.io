#include <iostream>
using namespace std;
#define infinity 9999
#define ROW 10
#define COL 10
class C_15
{
int graph[ROW][COL], nodes;
public:
void createGraph()
{
int i, j;
cout << "Enter total number of cities: ";
cin >> nodes;
cout << endl;
cout << "Enter the cost of connecting each pair of cities: " << endl;
for (i = 0; i < nodes; i++)
{
for (j = i; j < nodes; j++)
{
cout << "Enter the cost of connecting city " << i + 1 << " and city " << j + 1 << ":";
cin >> graph[i][j];
graph[j][i] = graph[i][j];
cout << endl;
}
}
for (i = 0; i < nodes; i++)
{
for (j = 0; j < nodes; j++)
{
if (graph[i][j] == 0)
{
graph[i][j] = infinity;
}
}
}
}
void primsAlgo()
{
int selected[ROW], zero = 0, one = 1, min = 0, i, j, x, y, ne = 0;
int cost = 0;
for (i = 0; i < nodes; i++)
{
selected[i] = zero;
}
selected[0] = one;
while(ne < nodes-1){
min = infinity;
for(i=0;i<nodes;i++){
if(selected[i]==one){
for(j=0;j<nodes;j++){
if(selected[j]==zero){
if(min > graph[i][j]){
min = graph[i][j];
x = i;
y = j;
}
}
}
}
}
selected[y] = one;
cout<<"Edge "<<x+1<<"->"<<y+1<<" is selected with cost "<<min<<endl;
cost+=graph[x][y];
ne++;
}
cout << "The minimum cost of connecting all the cities is: " << cost << endl;
}
};
int main()
{
C_15 obj;
obj.createGraph();
obj.primsAlgo();
return 0;
}
