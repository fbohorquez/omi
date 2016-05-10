//numData.h
//----------------------------------------------------------------------
/*
 * Fco. Javier Bohórquez Ogalla
 * 75766599-E
 * Puerto Real (Cádiz)
 * powersgame@gmail.com
 */
//----------------------------------------------------------------------
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */
//----------------------------------------------------------------------
#ifndef _NUMDATA_
#define _NUMDATA_
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <math.h>
using namespace boost::multiprecision;
using namespace std;
class numData {
   public:
      numData ();
      numData (const numData& n);
      numData (char* str);
      numData (double n);
      numData (float n);
      numData (int n);
      numData (long unsigned int n);
      numData (long int n);
      numData (unsigned int n);
      numData (std::basic_istream<char>::pos_type n);
      
      operator int() { return num_; }
      operator double() { return num_; }
      operator float() { return num_; }
      operator bool() { return num_; }
      operator long int() { return num_; }
      operator long unsigned int() { return num_; }
      operator unsigned int() { return num_; }
      
      inline numData operator+(numData lhs){
         return lhs.num_ + this->num_;
      }
      inline numData operator-(numData lhs){
         return this->num_ - lhs.num_;
      }
      inline numData operator-(){
         return -this->num_;
      }
      inline numData operator*(numData lhs){
         return lhs.num_ * this->num_;
      }
      inline numData operator/(numData lhs){
         return this->num_ / lhs.num_;
      }
      inline numData operator%(numData lhs){
         int a = lhs.num_, b = this->num_;
         return b % a;
      }
      
      inline numData& operator+=(const numData& rhs){
         this->num_ += rhs.num_;
         return *this;
      }
      inline numData& operator-=(const numData& rhs){
         this->num_ -= rhs.num_;
         return *this;
      }
      inline numData& operator/=(const numData& rhs){
         this->num_ /= rhs.num_;
         return *this;
      }
      inline numData& operator*=(const numData& rhs){
         this->num_ *= rhs.num_;
         return *this;
      }
      inline numData& operator%=(const numData& rhs){
         this->num_ *= rhs.num_;
         return *this;
      }

      inline double getNum () const {
         return num_;
      }   
      inline double& getNum () {
         return num_;
      }   
   private:
      double num_;
};
//~ typedef number<cpp_dec_float<100> > numData; 
//~ typedef int128_t numInt; 

ostream& operator<<(ostream& os, const numData& obj);

istream& operator>>(istream& is, numData& obj);

 bool operator==(const numData& lhs, const numData& rhs);
 bool operator==(const int& lhs, const numData& rhs);
 bool operator==(const numData& lhs, const int& rhs);
 bool operator==(const double& lhs, const numData& rhs);
 bool operator==(const numData& lhs, const double& rhs);
//~  bool operator==(const numData& lhs, std::basic_istream<char>::pos_type& rhs);

 bool operator!=(const numData& lhs, const numData& rhs);
 bool operator!=(const int& lhs, const numData& rhs);
 bool operator!=(const numData& lhs, const int& rhs);
 bool operator!=(const double& lhs, const numData& rhs);
 bool operator!=(const numData& lhs, const double& rhs);

 bool operator< (const numData& lhs, const numData& rhs);
 bool operator< (const int& lhs, const numData& rhs);
 bool operator< (const numData& lhs, const int& rhs);
 bool operator< (const double& lhs, const numData& rhs);
 bool operator< (const numData& lhs, const double& rhs);


 bool operator> (const numData& lhs, const numData& rhs);
 bool operator> (const int& lhs, const numData& rhs);
 bool operator> (const numData& lhs, const int& rhs);
 bool operator> (const double& lhs, const numData& rhs);
 bool operator> (const numData& lhs, const double& rhs);

 bool operator<=(const numData& lhs, const numData& rhs);
 bool operator<=(const int& lhs, const numData& rhs);
 bool operator<=(const numData& lhs, const int& rhs);
 bool operator<=(const double& lhs, const numData& rhs);
 bool operator<=(const numData& lhs, const double& rhs);

 bool operator>=(const numData& lhs, const numData& rhs);
 bool operator>=(const int& lhs, const numData& rhs);
 bool operator>=(const numData& lhs, const int& rhs);
 bool operator>=(const double& lhs, const numData& rhs);
 bool operator>=(const numData& lhs, const double& rhs);

numData pow (numData a, numData b ) ;

typedef NUMTYPE num;
typedef REFCTYPE refC;

#endif


