//numData.cpp
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

//----------------------------------------------------------------------
#include "numData.h"


//----------------------------------------------------------------------

//----------------------------------------------------------------------
numData::numData () { 
   num_ = 0;
}

numData::numData (char* str) { 
   num_ = atof (str);
}

numData::numData (const numData& n) { 
   num_ = n.num_;
}

numData::numData (double n){
   num_ = n;
}

numData::numData (float n){
   num_ = n;
}

numData::numData (int n) {
   num_ = n;
}

numData::numData (long unsigned int n) {
   num_ = n;
}

numData::numData (long int n) {
   num_ = n;
}

numData::numData (unsigned int n) {
   num_ = n;
}

numData::numData (std::basic_istream<char>::pos_type n) {
   num_ = n;
}

numData::operator int() { return num_; }

numData::operator double() { return num_; }

numData::operator float() { return num_; }

numData::operator bool() { return num_; }

numData::operator long int() { return num_; }

numData::operator long unsigned int() { return num_; }

numData::operator unsigned int() { return num_; }
//----------------------------------------------------------------------

//----------------------------------------------------------------------
ostream& operator<<(ostream& os, const numData& obj) {
   os << obj.getNum();   
   return os;
}

istream& operator>>(istream& is, numData& obj)
{
  is >> obj.getNum();
  return is;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
 bool operator==(const numData& lhs, const numData& rhs){ return lhs.getNum() == rhs.getNum();}
 bool operator==(const int& lhs, const numData& rhs){ return lhs == rhs.getNum(); }
 bool operator==(const numData& lhs, const int& rhs){ return rhs == lhs;}
 bool operator==(const double& lhs, const numData& rhs){ return lhs == rhs.getNum(); }
 bool operator==(const numData& lhs, const double& rhs){ return rhs == lhs;}
//~  bool operator==(const numData& lhs, std::basic_istream<char>::pos_type& rhs){ return rhs == lhs.getNum();}

 bool operator!=(const numData& lhs, const numData& rhs){return !operator==(lhs,rhs);}
 bool operator!=(const int& lhs, const numData& rhs){return !operator==(lhs,rhs);}
 bool operator!=(const numData& lhs, const int& rhs){return !operator==(lhs,rhs);}
 bool operator!=(const double& lhs, const numData& rhs){return !operator==(lhs,rhs);}
 bool operator!=(const numData& lhs, const double& rhs){return !operator==(lhs,rhs);}

 bool operator< (const numData& lhs, const numData& rhs){ return  lhs.getNum() < rhs.getNum(); }
 bool operator< (const int& lhs, const numData& rhs){ return lhs < rhs.getNum(); }
 bool operator< (const numData& lhs, const int& rhs){ return lhs.getNum() < rhs; }
 bool operator< (const double& lhs, const numData& rhs){ return lhs < rhs.getNum(); }
 bool operator< (const numData& lhs, const double& rhs){ return lhs.getNum() < rhs; }


 bool operator> (const numData& lhs, const numData& rhs){return  operator< (rhs,lhs);}
 bool operator> (const int& lhs, const numData& rhs){return  operator< (rhs,lhs);}
 bool operator> (const numData& lhs, const int& rhs){return  operator< (rhs,lhs);}
 bool operator> (const double& lhs, const numData& rhs){return  operator< (rhs,lhs);}
 bool operator> (const numData& lhs, const double& rhs){return  operator< (rhs,lhs);}

 bool operator<=(const numData& lhs, const numData& rhs){return !operator> (lhs,rhs);}
 bool operator<=(const int& lhs, const numData& rhs){return !operator> (lhs,rhs);}
 bool operator<=(const numData& lhs, const int& rhs){return !operator> (lhs,rhs);}
 bool operator<=(const double& lhs, const numData& rhs){return !operator> (lhs,rhs);}
 bool operator<=(const numData& lhs, const double& rhs){return !operator> (lhs,rhs);}

 bool operator>=(const numData& lhs, const numData& rhs){return !operator< (lhs,rhs);}
 bool operator>=(const int& lhs, const numData& rhs){return !operator< (lhs,rhs);}
 bool operator>=(const numData& lhs, const int& rhs){return !operator< (lhs,rhs);}
 bool operator>=(const double& lhs, const numData& rhs){return !operator< (lhs,rhs);}
 bool operator>=(const numData& lhs, const double& rhs){return !operator< (lhs,rhs);}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
numData pow (numData a, numData b ) { return numData (pow (a.getNum(), b.getNum())); }
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
