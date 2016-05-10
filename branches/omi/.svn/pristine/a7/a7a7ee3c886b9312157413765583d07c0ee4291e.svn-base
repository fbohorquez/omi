#!/usr/bin/env bash

check_script () {
   cd $1;
   local SCRIPT=$2
   local TEST_FILE=${SCRIPT/.lsh/.test}
   if [ -f $TEST_FILE ]; then 
      if  `diff <(./$SCRIPT 2>&1) $TEST_FILE 2> /dev/null` ; then 
         echo -e " -- $1/$2: \e[32mOK\e[0m";
      else
         echo -e " -- $1/$2: \e[31mERROR\e[0m";
      fi
   else
      echo -e " -- $1/$2: \e[33mFILE TEST DONT EXIST\e[0m"
   fi
}

check_dir () {
   echo "Check dir: $1" 
   local DIR=$1
   local LS=`ls $DIR`
   local TEST_SUBDIR=""
   for TEST_SUBDIR in $LS; do 
      if [ $DIR/$TEST_SUBDIR != $1 ]; then 
         if [ -d $DIR/$TEST_SUBDIR ]; then
            check_dir $DIR/$TEST_SUBDIR
         else
            [[ $TEST_SUBDIR =~ .*lsh ]] && check_script $DIR $TEST_SUBDIR
         fi
      fi
   done
}


TEST_DIR="/home/franj/projects/omi.svn/test";
check_dir $TEST_DIR
