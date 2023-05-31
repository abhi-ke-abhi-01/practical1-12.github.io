#include<iostream>
#include <fstream>
using namespace
std;
class Record
{ int id;
string
name; int
salary;
string designation;
public:
Record();
int getIdno();
void
getData();
void
putData();
};
Record::Record()
 {
  id = 0;
name = ' ';
designation =' '; 
salary = 0;
}
int
Record::getIdno()
{ 
return (id);
}
void Record::getData() {
cout << "\nEnter Details:"; cout << "\nId no: ";
cin >> id;
cout << "Name:"; cin >> name;
cout << "Salary:"; cin >> salary;
cout << "Designation:"; cin >> designation;
}
void
Record::putData() {
cout << "\nId No.:"; cout << id;
cout << "\t\tName:"; cout << name;
cout << "\nSalary:"; cout << salary;
cout << "\tDesignation:"; cout << designation;
}
class File {
ifstream
fin;
ofstream
fout; fstream
fs;
public:
void insert();
void display();
void
search(int); int
Delete(int); int
edit(int);
};
void
File::insert() {
Record r;
r.getData();
fout.open("EmployeeDB", ios::ate |
ios::app); fout.write((char *)&r,
sizeof(r));
fout.close();
}
void
File::display() {
Record r;
fin.open("EmployeeDB"); fin.seekg(0,
ios::beg);
while (fin.read((char *)&r,
sizeof(r))) r.putData();
fin.close();
}
void File::search(int
id) { Record r;
int flag = 0;
fin.open("EmployeeDB"); fin.seekg(0,
ios::beg);
while (fin.read((char *)&r,
sizeof(r))) { if (r.getIdno() ==
id) {
flag =
1;
break;
}
}
fin.close();
if (flag == 1) {
cout << "\nRecordFound:"; r.putData();
}
else
cout << "\nRecord not Found ";
}
int File::Delete(int
id) { Record r;
int flag = 0;
fin.open("EmployeeDB");
fout.open("Temp", ios::ate |
ios::app); fin.seekg(0, ios::beg);
while (fin.read((char *)&r,
sizeof(r))) { if (r.getIdno() ==
id) {
flag = 1;
}
else {
fout.write((char *)&r, sizeof(r));
}
}
fin.close();
fout.close();
remove("EmployeeDB");
rename("Temp",
"EmployeeDB"); return (flag);
}
int File::edit(int
id) { Record r;
int flag = 0;
fs.open("EmployeeDB");
fs.seekg(0, ios::beg);
while (fs.read((char *)&r,
sizeof(r))) { if (r.getIdno() ==
id) {
flag = 1;
cout << "\nEnter NewDetails: "; r.getData();
fs.seekp((int)fs.tellg() - sizeof(r),
ios::beg); fs.write((char *)&r,
sizeof(r));
}
}
fs.close();
return
(flag);
}
int main()
{ File f;
int ch, n, i, flag =
0; do {
cout << "\n\n\t-----M E N U ";
cout << "\n\n1. Build A MasterTable"; 
cout << "\n2. List ATable";
cout << "\n3. Insert a NewEntry"; cout << "\n4. DeleteOld Entry";
 cout << "\n5. Editan Entry";
cout << "\n6. Search for aRecord"; cout << "\n7. Quit";
cout << "\nEnter yourChoice: "; cin >> ch;
switch (ch)
{ case 1:
if (flag == 0) {
cout << "\nEnter No of Records to insert: "; cin >> n;
for (i = 0; i < n;
i++) { f.insert();
}
flag = 1;
}
else {
cout << "\nSorry.. Table is Already build \n If want to add record pleaseselect Insert a New Entry in option .";
}
break
; case
2:
f.display(
); break;
case 3:
f.insert()
; break;
case 4:
cout << "\nEnter Id No of Employee Whose Record is to beDeleted: "; cin >> n;
i =
f.Delete(n);
if (i == 1)
cout << "\nRecord DeletedSuccessfully"; else
cout << "\nRecord notFound"; break;
case 5:
cout << "\nEnter Id No of Employee Whose Record is to beEdit: "; cin >> n;
i =
f.edit(n); if
(i == 1)
cout << "\nRecord ModifiedSuccessfully"; else
cout << "\nRecord notFound"; break;
case 6:
cout << "\nEnter Id No of Employee Whose Record is to beSearched: "; cin >> n;
f.search(n)
; break;
case 7:
break
;
default:
cout << "\nEnter Valid Choice. ";
}
} while (ch !=
7); return (0);
}

