#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;

namespace zich{
    class Matrix{
    private:
        int rows;
        int colmns;
        map<int,map<int,int>>mCalculate;
    public:
        Matrix(vector<double>v,int rows, int column){
        
        }
        /*
        here is aoprators function that give as amore operate that we want to do 
        */
        friend ostream &operator<<(ostream &output,const Matrix &m);
        friend istream &operator>>(istream &output,const Matrix &m);
        friend Matrix operator+(const Matrix &m1,const Matrix &m2);
        friend Matrix operator-(const Matrix &m1,const Matrix &m2);
        friend Matrix operator+=(const Matrix &m1,const Matrix &m2);
        friend Matrix operator-=(const Matrix &m1,const Matrix &m2);
        friend Matrix operator+(const Matrix &m1);
        friend Matrix operator-(const Matrix &m1);
        friend Matrix operator*(const Matrix &m1,const Matrix &m2);
        friend Matrix operator*=(const Matrix &m1,const Matrix &m2);
        friend Matrix operator*(double num,const Matrix &m1);
        friend Matrix operator*=(const Matrix &m1,double num);
        friend bool operator>(const Matrix &m1,const Matrix &m2);
        friend bool operator<(const Matrix &m1,const Matrix &m2);
        friend bool operator>=(const Matrix &m1,const Matrix &m2);
        friend bool operator<=(const Matrix &m1,const Matrix &m2);
        friend bool operator==(const Matrix &m1,const Matrix &m2);
        friend bool operator!=(const Matrix &m1,const Matrix &m2);
        friend Matrix operator++(const Matrix &m1);
        friend Matrix operator--(const Matrix &m1);

    };
}
