#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
const int MAX=20;
class Student
{
 int rollno;
char name[20],city[20];
char div;
int year;
public:
Student()
{
 strcpy(name,"");
 strcpy(city,"");
 rollno=year=div=0;
}
Student(int rollno,char name[MAX],int year,char div,char city[MAX])
{
 strcpy(this->name,name);
 strcpy(this->city,city);
 this->rollno=rollno;
 this->year=year;
 this->div=div;
}
int getRollNo()
{
 return rollno;
}
void displayRecord()
{

cout<<endl<<setw(5)<<rollno<<setw(10)<<name<<setw(5)<<year<<setw(5)<<div<
<setw(10)<<city;
}
};
class FileOp
{
fstream file;
public:
FileOp(char* filename)
{
file.open(filename);//,ios::in|ios::out|ios::ate|ios::binary
}
void insertRecord(int rollno, char name[MAX],int year, char div,char
city[MAX])
 {
 Student s1(rollno,name,year,div,city);
 file.seekp(0,ios::end);
 file.write((char *)&s1,sizeof(Student));
 file.clear();
}
void displayAll()
{
 Student s1;
 file.seekg(0,ios::beg);
 while(file.read((char *)&s1, sizeof(Student)))
 {
 s1.displayRecord();
}
 file.clear();
}
void displayRecord(int rollNo)
{
 Student s1;
 file.seekg(0,ios::beg);
 bool flag=false;
 while(file.read((char*)&s1,sizeof(Student)))
 {
 if(s1.getRollNo()==rollNo)
 {
 s1.displayRecord();
 flag=true;
 break;
 }
 }
 if(flag==false)
 {
 cout<<"\nRecord of "<<rollNo<<"is not present.";
 }
 file.clear();
}
void deleteRecord(int rollno)
{
 ofstream outFile("new.txt",ios::binary);
 file.seekg(0,ios::beg);
 bool flag=false;
 Student s1;
while(file.read((char *)&s1, sizeof(Student)))
 {
 if(s1.getRollNo()==rollno)
 {
 flag=true;
 continue;
 }
 outFile.write((char *)&s1, sizeof(Student));
 }
 if(!flag)
 {
 cout<<"\nRecord of "<<rollno<<" is not present.";
 }
 file.close();
 outFile.close();
 remove("student1.txt");
 rename("new.txt","student1.txt");
 file.open("student1.txt");//,ios::in|ios::out|ios::ate|ios::binary
 }
~FileOp()
{
 file.close();
 cout<<"\nFile Closed.";
}
};
int main()
{
ofstream newFile("student1.txt");
 newFile.close();
 FileOp file((char*)"student1.txt");
 int rollNo,year,ch=0;
 char div;
 char name[MAX],address[MAX];
 while(ch!=5)
 {
cout<<"\n*****Student Database*****\n";
 cout<<"1) Add New Record\n";
 cout<<"2) Display All Records\n";
 cout<<"3) Display by RollNo\n";
 cout<<"4) Deleting a Record\n";
 cout<<"5) Exit\n";
 cout<<"Choose your choice : ";
 cin>>ch;
 switch(ch)
 {
 case 1 :
 cout<<endl<<"Enter RollNo : \n";
 cin>>rollNo;
 cout<<"Enter name : \n";
 cin>>name;
 cout<<"Enter Year : \n";
 cin>>year;
 cout<<"Enter Division : \n";
 cin>>div;
 cout<<"Enter address : \n";
 cin>>address;
 file.insertRecord(rollNo,name,year,div,address);
 cout<<"\nRecord Inserted.";
 break;
 case 2 :

cout<<endl<<setw(5)<<"ROLL"<<setw(10)<<"NAME"<<setw(5)<<"YEAR"<<setw(5)<<"
DIV"<<setw(10)<<"CITY";
 file.displayAll();
 break;
 case 3 :
 cout<<"Enter Roll Number";
 cin>>rollNo;
 file.displayRecord(rollNo);
break;
 case 4:
 cout<<"Enter rollNo";
 cin>>rollNo;
 file.deleteRecord(rollNo);
 break;
 case 5 :
 break;
}
 }
 return 0;
}
