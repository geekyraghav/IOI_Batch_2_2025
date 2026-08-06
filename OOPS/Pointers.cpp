#include<iostream>
using namespace std;
class Student{
public:
    string name;
    double cgpa;
    int rno;
};
int main(){
    Student s1 = {"Abhishek",6,3};
    Student* p = &s1;
    // (*p).name = "Amitabh";
    p->name = "Amitabh";
    cout<<s1.name;
}