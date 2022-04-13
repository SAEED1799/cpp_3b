#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <vector>
#include "Matrix.hpp"
using namespace std;

namespace zich{

         ostream &operator<<(ostream &output,const Matrix &m){
             return output;
         }
         istream &operator>>(istream &output,const Matrix &m){
              return output;
         }
         Matrix operator+(const Matrix &m1,const Matrix &m2){
               vector<double> result;
               return Matrix(result, m1.rows, m1.colmns);

         }
         Matrix operator-(const Matrix &m1,const Matrix &m2){
                return m1;
         }
         Matrix operator+=(const Matrix &m1,const Matrix &m2){
             return m1;
         }
         Matrix operator-=(const Matrix &m1,const Matrix &m2){
              return m1;
         }
         Matrix operator+(const Matrix &m1){
              return m1;
         }
         Matrix operator-(const Matrix &m1){
              return m1;
         }
         Matrix operator*(const Matrix &m1,const Matrix &m2){
              return m1;
         }
         Matrix operator*=(const Matrix &m1,const Matrix &m2){
              return m1;
         }
         Matrix operator*(double num,const Matrix &m1){
              return m1;
         }
         Matrix operator*=(const Matrix &m1,double num){
              return m1;
         }
         bool operator>(const Matrix &m1,const Matrix &m2){
             return true;
         }
         bool operator<(const Matrix &m1,const Matrix &m2){
             return true;
         }
         bool operator>=(const Matrix &m1,const Matrix &m2){
             return true;
         }
         bool operator<=(const Matrix &m1,const Matrix &m2){
             return true;
         }
         bool operator==(const Matrix &m1,const Matrix &m2){
             return true;
         }
         bool operator!=(const Matrix &m1,const Matrix &m2){
             return true;
         }
         Matrix operator++(const Matrix &m1){
              return m1;
         }
         Matrix operator--(const Matrix &m1){
              return m1;
         }

    
}
