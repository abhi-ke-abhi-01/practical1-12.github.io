#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 30;
class node
{
node *next;
string city;
int timeCost;
public:
friend class graph;
node()
{
next = NULL;
city = "";
timeCost = 0;
}
node(string city, int time)
{
next = NULL;
this->city = city;
timeCost = time;
}
};
class graph
{
node *head[MAX];
int n;
public:
graph(int num)
{
n = num;
for (int i = 0; i < n; i++)
{
head[i] = NULL;
}
}
void insert(string city1, string city2, int time);
void readdata();
void display();
int getIndex(string city);
};
int graph::getIndex(string s1)
{
for (int i = 0; i < n; i++)
{
if (head[i]->city == s1)
{
return i;
}
}
return -1;
}
void graph::insert(string city1, string city2, int time)
{
node *source;
node *dest = new node(city2, time);
int index = getIndex(city1);
source = head[index];
while (source->next != NULL)
{
source = source->next;
}
source->next = dest;
}
void graph::display() {
node *source;
for(int i=0;i<n;i++){
source=head[i];
while(source!=NULL){
cout<<source->city<<"->";
source=source->next;
}
cout<<"NULL"<<endl;
}
}
void graph::readdata() {
string city1,city2, tempcity;
int fcost, flight;
cout<<"Enter city details: "<<endl;
for(int i=0;i<n;i++){
head[i]=new node();
cout<<"Enter name of city: "<<i+1<<endl;
cin>>head[i]->city;
}
cout<<"Enter number of flights: "<<endl;
cin>>flight;
for(int i=0;i<flight;i++){
cout<<"Enter source city: "<<endl;
cin>>city1;
cout<<"Enter destination city: "<<endl;
cin>>city2;
cout<<"Enter time: "<<endl;
cin>>fcost;
insert(city1,city2,fcost);
}
}
int main() {
int number, choice;
cout<<"Enter number of cities: "<<endl;
cin>>number;
graph g1(number);
do {
cout<<"***********************************************************"<<endl;
cout<<"1. Enter data"<<endl;
cout<<"2. Display data"<<endl;
cout<<"3. Exit"<<endl;
cout<<"***********************************************************"<<endl;
cout<<"Enter your choice: "<<endl;
cin>>choice;
switch(choice){
case 1:
g1.readdata();
break;
case 2:
g1.display();
break;
case 3:
break;
default:
cout<<"Invalid choice"<<endl;
}
}while(choice != 3);
return 0;
}
