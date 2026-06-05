#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct student{
//Create student node:
int id;
string name;
int  mark;
student *next;
};
student *head=NULL;
student *temp=NULL;
void addstudent();
void searchbyid();
void display();
void deletebyid();
void updateidnamemark();
student *createnode(int id,string name,int mark);
int main(){
cout<<"***********************************************"<<endl;
cout<<"1.add student\n 2.display all student\n 3.search by id\n 4.delete by id\n  5.update mark\n"<<endl;
int choice;
do{
cout<<"enter the choice"<<endl;
cin>>choice;
if(choice==1){
addstudent();
}
else if(choice==2){
cout<<"display students data"<<endl;
display();
}
else if(choice==3){
searchbyid();
}
else if(choice==4){
deletebyid();
}
else if(choice==5){
updateidnamemark();
}
}while(choice!=6);
return 0;
}
void addstudent(){
cout<<"add student"<<endl;
int  n;
int id;
string name;
int marks;
cout<<"enter the numbers of student"<<endl;
cin>>n;
for(int i=0;i<n;i++){
cout<<"enter the id"<<endl;
cin>>id;
cout<<"enter the name"<<endl;
cin.ignore();
getline(cin,name);
cout<<"enter the marks"<<endl;
cin>>marks;
student *newnode=createnode(id,name,marks);
if(head==NULL){
head=newnode;
temp=newnode;
}
else{
temp->next=newnode;
temp=newnode; }
}
}
student *createnode(int id,string name,int mark){
student *newnode=new student;
newnode->id=id;
newnode->name=name;
newnode->mark=mark;
newnode->next=NULL;
return newnode;
}
void display(){
temp=head;
//ofstream file("studentsdata.txt",ios::app);
while(temp!=NULL){
//file<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
temp=temp->next;
}
//file.close();
temp=NULL;
}
void searchbyid(){
temp=head;
int i=0;
//ifstream file("studentsdata.txt");
//string line;
//while(getline(file,line)){
//cout<<line<<endl;
//}
//file.close();
cout<<"enter the id "<<endl;
int id;
cin>>id;
while(temp!=NULL){
if(temp->id==id){
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
break;
}
temp=temp->next;
}
temp=NULL;
}
void deletebyid(){
temp=head;
cout<<"enter the id to delete in  the student database"<<endl;
int id;
cin>>id;
student *prev=NULL;
while(temp!=NULL){
if(temp->id==id){
if(head==temp){
cout<<"the deleting node....."<<endl;
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
head=head->next;
break;
}
else{
cout<<"the deleting node....."<<endl;
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
prev->next=temp->next;
delete temp;
break;
}
}
prev=temp;
temp=temp->next;
}
}
void updateidnamemark(){
int choice;
cout<<"enter the choice to update id or name or marks "<<endl;
do{
cout<<"1.id\n2.name\n3.marks\n"<<endl;
cin>>choice;
if(choice==1){
cout<<"enter the id to update"<<endl;
int id;
cin>>id;
temp=head;
while(temp!=NULL){
if(temp->id==id){
int newid;
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
cout<<"enter the new id"<<endl;
cin>>newid;
temp->id=newid;
break;
}
temp=temp->next;
}
}
else if(choice==2){
cout<<"enter the name to update"<<endl;
string name;
cin>>name;
temp=head;
while(temp!=NULL){
if(temp->name==name){
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
cout<<"enter the new name"<<endl;
string newname;
cin>>newname;
temp->name=newname;
break;
}
temp=temp->next;
}
}
else if(choice==3){
cout<<"enter the id to update marks"<<endl;
int id;
cin>>id;
while(temp!=NULL){
if(temp->id==id){
cout<<temp->id<<":"<<temp->name<<":"<<temp->mark<<endl;
cout<<"enter the new mark to update"<<endl;
int newmark;
cin>>newmark;
temp->mark=newmark;
break;
}
temp=temp->next;
}
}
}while(choice!=4);
}
