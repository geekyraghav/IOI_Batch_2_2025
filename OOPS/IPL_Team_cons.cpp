#include<iostream>
using namespace std;
class IPL_Team{
public:
    int trophies = 0;
    string name = "BCCI";
    void print(){
        cout<<name<<" "<<trophies<<endl;
    }
    IPL_Team(){
        
    }
    IPL_Team(int t, string n){
        name = n;
        trophies = t;
    }
    IPL_Team(string n, int t){
        name = n;
        trophies = t;
    }
    IPL_Team(string n){
        name = n;
    }
};
int main(){
    IPL_Team t1(2,"RCB");
    IPL_Team t2(5,"M1");
    IPL_Team t3("LSG",0);
    IPL_Team t4;
    t4.name = "SRH";
    t4.trophies = 1;
    IPL_Team t5("CSK");
    t3.print();
    IPL_Team t6;
    t6.print();
}