#include<iostream>
using namespace std;
class Fraction{
public:
    int num;
    int den;
    Fraction(){
        
    }
    Fraction(int num, int den){
        this->num = num;
        this->den = den;
        simplify();
    }
    void print(){
        if(den==1) cout<<num<<endl;
        else cout<<num<<"/"<<den<<endl;
    }
    void add(Fraction f){
        num = num * f.den + f.num * den;
        den = den * f.den;
        simplify();
    }
    void multiply(Fraction f){
        num *= f.num;
        den *= f.den;
        simplify();
    }
    void simplify(){
        int hcf = gcd(num,den);
        num /= hcf;
        den /= hcf;
    }
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
};

int main(){
    Fraction f1(6,8);
    Fraction f2(1,4);
    f1.print();
    f1.add(f2);
    f1.print();
}