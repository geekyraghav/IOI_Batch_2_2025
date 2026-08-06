#include<iostream>
using namespace std;
class Complex{
public:
    double real;
    double imaginary;
    Complex(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    void add(Complex c){
        real += c.real;
        imaginary += c.imaginary;
    }
    void multiply(Complex c){
        real = real*c.real - imaginary*c.imaginary;
        imaginary = real*c.imaginary + imaginary*c.real;
    }
    void divide(Complex c){
        Complex conjugate(c.real,-c.imaginary);
        multiply(conjugate);
        double modSquare = (c.real*c.real + c.imaginary*c.imaginary);
        real /= modSquare;
        imaginary /= modSquare;
    }
    
};

int main(){
    
}