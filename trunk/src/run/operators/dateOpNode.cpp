//dateOpNode.cpp
//-------------------------------------------------------------------------------------------
/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#include "dateOpNode.h"
#include "../../error.h"
#include "../../interpreter.h"
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//dateNode
dateNode::dateNode(runNode * str, runNode * timestamp) : str_(str), timestamp_(timestamp) {}

void dateNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode * str = str_, *timestamp = timestamp_;
   nexpNode::resolved(str);
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   if(timestamp)
      nexpNode::resolved(timestamp);
      #if JSON==1
         interpreter::to_jsonRun(this);
      #endif
   time_t now = timestamp?arithNode::to_num(timestamp):time(0);
   tm *ltm = localtime(&now);
   if(stringNode *s = dynamic_cast<stringNode*>(str)) {
      string exp = s->strvalue();
      int pos = 0;
      while((pos = exp.find('%', pos)) != string::npos) {
         if(pos < exp.size() - 1) {
            char c = exp[pos + 1];
            string date_text = "";
            switch(c) {
            case 'd': date_text = run_day(ltm); break;
            case 'D': date_text = run_week3(ltm); break;
            case 'j':  date_text = run_day_zero(ltm); break;
            case 'l': date_text = run_week(ltm); break;
            case 'w': date_text = run_week_num(ltm); break;
            case 'z': date_text = run_day_year(ltm); break;
            case 'F': date_text = run_month_str(ltm); break;
            case 'm': date_text = run_month_num(ltm); break;
            case 'M': date_text = run_month3_str(ltm); break;
            case 'n': date_text = run_month_num_zero(ltm); break;
            case 'Y': date_text = run_year(ltm); break;
            case 'y': date_text = run_year2(ltm); break;
            case 'a': date_text = run_am(ltm); break;
            case 'A': date_text = run_AM(ltm); break;
            case 'g': date_text = run_hour_12_zero(ltm); break;
            case 'G': date_text = run_hour_24_zero(ltm); break;
            case 'h': date_text = run_hour_12(ltm); break;
            case 'H': date_text = run_hour_24(ltm); break;
            case 'i': date_text = run_minute(ltm); break;
            case 's': date_text = run_second(ltm); break;
            case 'U': date_text = run_unixtime(now); break;
            case '%': date_text = "%"; break;
            default: date_text = exp.substr(pos,2); break;
            }
            exp.replace(pos, 2, date_text);
         }
         pos ++;
      }
      this->strvalue_ = exp;
      #if JSON==1
         interpreter::to_jsonSetValue(this, this->strvalue_);
      #endif      
   }
}

string dateNode::run_day(tm *ltm) {
   ostringstream oss;
   if(ltm->tm_mday < 10)
      oss << "0";
   oss << ltm->tm_mday;
   return oss.str();
}

string dateNode::run_week3(tm *ltm) {
   string week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
   ostringstream oss;
   oss << week[ltm->tm_wday];
   return oss.str();
}

string dateNode::run_day_zero(tm *ltm) {
   ostringstream oss;
   oss << ltm->tm_mday;
   return oss.str();
}

string dateNode::run_week(tm *ltm) {
   string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
   ostringstream oss;
   oss << week[ltm->tm_wday];
   return oss.str();
}

string dateNode::run_week_num(tm *ltm) {
   ostringstream oss;
   oss << ltm->tm_wday;
   return oss.str();
}

string dateNode::run_day_year(tm *ltm) {
   ostringstream oss;
   oss << ltm->tm_yday;
   return oss.str();
}

string dateNode::run_month_str(tm *ltm) {
   ostringstream oss;
   string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
   oss << month[ltm->tm_mon];
   return oss.str();
}

string dateNode::run_month_num(tm *ltm) {
   ostringstream oss;
   if(ltm->tm_mon < 9)
      oss << "0";
   oss << ltm->tm_mon + 1;
   return oss.str();
}

string dateNode::run_month3_str(tm *ltm) {
   ostringstream oss;
   string month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
   oss << month[ltm->tm_mon];
   return oss.str();
}

string dateNode::run_month_num_zero(tm *ltm) {
   ostringstream oss;
   oss << ltm->tm_mon + 1;
   return oss.str();
}

string dateNode::run_year(tm *ltm) {
   ostringstream oss;
   oss << 1900 + ltm->tm_year;
   return oss.str();
}

string dateNode::run_year2(tm *ltm) {
   ostringstream oss;
   oss << 1900 + ltm->tm_year;
   return oss.str().substr(2);
}

string dateNode::run_am(tm *ltm) {
   ostringstream oss;
   oss <<((ltm->tm_hour < 12)?"am":"pm");
   return oss.str();
}

string dateNode::run_AM(tm *ltm) {
   ostringstream oss;
   oss <<((ltm->tm_hour < 12)?"AM":"PM");
   return oss.str();
}

string dateNode::run_hour_12_zero(tm *ltm) {
   ostringstream oss;
   oss <<((ltm->tm_hour != 12)?(ltm->tm_hour % 2):12);
   return oss.str();
}

string dateNode::run_hour_24_zero(tm *ltm) {
   ostringstream oss;
   oss << ltm->tm_hour;
   return oss.str();
}

string dateNode::run_hour_12(tm *ltm) {
   ostringstream oss;
   if(ltm->tm_hour < 10)
      oss << "0";
   oss <<((ltm->tm_hour != 12)?(ltm->tm_hour % 2):12);
   return oss.str();
}

string dateNode::run_hour_24(tm *ltm) {
   ostringstream oss;
   if(ltm->tm_hour < 10)
      oss << "0";
   oss << ltm->tm_hour;
   return oss.str();
}

string dateNode::run_minute(tm *ltm) {
   ostringstream oss;
   if(ltm->tm_min < 10)
      oss << "0";
   oss << ltm->tm_min;
   return oss.str();
}

string dateNode::run_second(tm *ltm) {
   ostringstream oss;
   if(ltm->tm_sec < 10)
      oss << "0";
   oss << ltm->tm_sec;
   return oss.str();
}

string dateNode::run_unixtime(time_t now) {
   ostringstream oss;
   oss << now;
   return oss.str();
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//timeNode
timeNode::timeNode () {}

void timeNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   numvalue_ =  time(0);
   #if JSON==1
      interpreter::to_jsonSetValue(this, numvalue_);
   #endif
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//sleepNode
sleepNode::sleepNode (runNode * s) : s_(s) {}

void sleepNode::run() {
   #if JSON==1
      interpreter::to_jsonRun(this);
   #endif   
   runNode *s = s_;
   nexpNode::resolved(s);
   #if JSON==1
      interpreter::to_jsonRun(this);
      if (interpreter::get()->json){
         interpreter::to_jsonSleep (this, arithNode::to_num(s));
      }else{
   #endif   
   if(dynamic_cast<arithNode*>(s)) {
      sleep(arithNode::to_num(s));
   }
   #if JSON==1
      }
   #endif   
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------


//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Fco. Javier Bohórquez Ogalla
