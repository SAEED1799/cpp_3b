#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>

using namespace zich;
using namespace std;

TEST_CASE("test for operators that 2 in rows"){
std::vector<double> arr1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> arr2 = {3, 0, 0, 0, 3, 0};
Matrix a{arr1, 3, 3};
Matrix a1{arr2, 3, 2};
CHECK_THROWS(a+a1);
CHECK_THROWS(a-a1);
CHECK_THROWS(a+=a1);
CHECK_THROWS(a-=a1);
CHECK_THROWS(a1*a);
CHECK_THROWS(a1*=a);



}
TEST_CASE("test for operators that 2 for column"){
std::vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> arr1 = {3, 0, 0, 0, 3, 0};
Matrix a{arr1, 3, 3};
Matrix a1{arr2, 3, 2};
CHECK_THROWS(a+a1);
CHECK_THROWS(a-a1);
CHECK_THROWS(a+=a1);
CHECK_THROWS(a-=a1);
CHECK_THROWS(a1*a);
CHECK_THROWS(a1*=a);



}


TEST_CASE("more matrix for the tests")
{
    std::vector<double> arr1 = {1,0,1,2,3,4,5,3,4};
    std::vector<double> arr2 = {4, 4, 6, -6, 5,-5,4,4,3};
    std::vector<double> arr3 = {9,6,7,3,-9,0,-0,9,8};
    std::vector<double> arr4 = {3,4,5,3,4,5,6,8,6};
    std::vector<double> arr5 = {3, 0, 0, 0, 3, 0};
    Matrix m1{arr1, 3, 3};
    Matrix m2{arr2, 3, 3};
    Matrix m3{arr3, 3, 3};
    Matrix m4{arr5, 3, 2};
    CHECK_THROWS(m2+m4);
    CHECK_THROWS(m1 += m4);
    CHECK_THROWS(m4 -m3);
    CHECK_THROWS(m2 -= m1);
    CHECK_THROWS(m3+ m3);
    CHECK_EQ(-m1 == m2,true);
    CHECK_NOTHROW(+m1);
    CHECK_EQ(+m1 == m1, true);
    CHECK_NOTHROW(++m1);
    CHECK_EQ(m1 == m3, true);
    CHECK_NOTHROW(--m1);
    CHECK_THROWS(m1 += m4);
    CHECK_THROWS(m1 -m1);
    CHECK_THROWS(m2 -= m1);
    CHECK_THROWS(-m1);
    CHECK_THROWS(m1+m4);
    CHECK_THROWS(m3 += m4);
    CHECK_THROWS(m2 -m3);
    CHECK_THROWS(m1 -= m1);
    CHECK_THROWS(m1+ m3);
    CHECK_EQ(-m4 == m2, true);
    
}
