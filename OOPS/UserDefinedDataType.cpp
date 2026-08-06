#include<iostream>
using namespace std;
class Student{
public:
    string name;
    double cgpa;
    int rno;
};
class Car{
public:
    string name;
    int price;
    int seats;
    int power;
};
int main(){
    Car c1;
    c1.name = "Scorpio";
    c1.power = 180;
    c1.seats = 7;
    Student s1;
    s1.name = "Prem";
    s1.cgpa = 6.8;
    s1.rno = 190;
    Student s2 = {"Udit",7.3,96};
    cout<<s2.name;
    Student s3;
}