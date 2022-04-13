#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <vector>
#include "Matrix.hpp"
using namespace std;

namespace zich
{

     Matrix::Matrix(vector<double> v, int rows, int cols)
     {

          if (v.size() != rows * cols || (rows < 0 || cols < 0))
          {

               throw "Invalid cols and rows";
          }
          this->_rows = rows;
          this->_cols = cols;
          unsigned int k = 0;
          for (int i = 0; i < rows; i++)
          {
               for (int j = 0; j < cols; j++)
               {
                    this->matMap[i][j] = v[k];
                    k++;
               }
          }
     }
     // A+B
     // A+=B
     Matrix Matrix::operator+(const Matrix &m1)
     {

          if ((_rows != m1._rows) || (_cols != m1._cols))
          {
               throw "Invalid cols and rows";
          }

          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(this->matMap[i][j] + m1.matMap.at(i).at(j));
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};

          return new_mat;
     }

     Matrix Matrix::operator-(const Matrix &m1)
     {

          if ((_rows != m1._rows) || (_cols != m1._cols))
          {
               throw "Invalid cols and rows";
          }

          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(this->matMap[i][j] - m1.matMap.at(i).at(j));
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};

          return new_mat;
     }

     Matrix &Matrix::operator+=(const Matrix &otherMat)
     {
          // throws
          *this = *this + otherMat;
          return *this;
     }

     Matrix &Matrix::operator-=(const Matrix &otherMat)
     {
          // throws
          *this = *this - otherMat;
          return *this;
     }

     Matrix &Matrix::operator++()
     {

          // throws

          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    this->matMap[i][j]++;
               }
          }

          return *this;
     }
     Matrix Matrix::operator++(int)
     {

          Matrix tempMat = *this;
          ++(*this);

          return tempMat;
     }

     Matrix &Matrix::operator--()
     {

          // throws

          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    this->matMap[i][j]--;
               }
          }

          return *this;
     }
     Matrix Matrix::operator++(int)
     {
          // throws
          Matrix tempMat = *this;
          --(*this);
          return tempMat;
     }

     Matrix Matrix::operator-()
     {

          // throws

          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(matMap[i][j] * -1);
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};
          return new_mat;
     }

     // ******* input/output******
     ostream &operator<<(ostream &output, const Matrix &m)
     {
          // throws
          string str;
          for (int i = 0; i < m._rows; i++)
          {
               str += "[";
               for (int j = 0; j < m._cols; j++)
               {
                    str += to_string(int(m.matMap.at(i).at(j)));
                    if (j != m._cols - 1)
                    {
                         str += " ";
                    }
               }
               str += "]";
               if (i != m._rows - 1)
               {
                    str += "\n";
               }
          }
          output << str;
          return output;
     }

     Matrix Matrix::operator+() // plus unary
     {
     }

     Matrix Matrix::operator-() // minus unary
     {
         
          vector<double> _newVec;
          for (int i = 0; i < _rows; i++)
          {
               for (int j = 0; j < _cols; j++)
               {

                    _newVec.push_back(matMap[i][j] * -1);
               }
          }

          Matrix new_mat{_newVec, _rows, _cols};
          return new_mat;
     }

     Matrix operator*(double num, const Matrix &m1)
     {
          // throws
          vector<double> _newVec;
          for (int i = 0; i < m1._rows; i++)
          {
               for (int j = 0; j < m1._cols; j++)
               {

                    _newVec.push_back(num * m1.matMap.at(i).at(j));
               }
          }

          Matrix new_mat{_newVec, m1._rows, m1._cols};
          return new_mat;
     }

     Matrix operator*(const Matrix &m1, double num)
     {
          // throws

          return num * m1;
     }

     Matrix &Matrix::operator*=(double num)
     {
          *this = (*this) * num;
          return *this;
     }

     Matrix Matrix::operator*(const Matrix &m1)
     {
     }

     Matrix &Matrix::operator*=(const Matrix &m1)
     {
     }

     istream &operator>>(std::istream &input, Matrix &matrix)
     {
          // throws
          return input;
     }

     bool operator>(const Matrix &m1, const Matrix &m2)
     {
          // throws

          return (sum_calculator(m1) > sum_calculator(m2));
     }
     bool operator<(const Matrix &m1, const Matrix &m2)
     {
          // throws
          return (sum_calculator(m1) < sum_calculator(m2));
     }
     bool operator>=(const Matrix &m1, const Matrix &m2)
     {

          bool ans = (m1 < m2);
          return !ans;
     }
     bool operator<=(const Matrix &m1, const Matrix &m2)
     {
          bool ans = (m1 > m2);
          return !ans;
     }

     bool operator==(const Matrix &m1, const Matrix &m2)
     {
          // m*n  m*n
          // thorws

          return !(m1 != m2);
     }

     bool operator!=(const Matrix &m1, const Matrix &m2)
     {
          for (int j = 0; j < m1._rows; j++)
          {
               for (int i = 0; i < m1._cols; i++)
               {
                    if (!(m1.matMap.at(j).at(i) == m2.matMap.at(j).at(i)))
                    {
                         return true;
                    }
               }
          }
          return false;
     }

     double sum_calculator(const Matrix &m1)
     {
          int sum = 0;

          for (int i = 0; i < m1._rows; i++)
          {
               for (int j = 0; j < m1._cols; j++)
               {

                    sum += m1.matMap.at(i).at(j);
               }
          }
          return sum;
     }

}
