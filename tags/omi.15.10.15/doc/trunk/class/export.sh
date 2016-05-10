#!/bin/bash
function processDir {
   LS=`ls $1`
   for I in $LS; do
      FILE="$PWD/$I";
      cd $1
      if [ -d "$FILE" ]; then
         cd $FILE;
         processDir $FILE
      else
         if [[ $FILE =~ png$ ]]; then
            mv $FILE ${FILE/.class/}
         fi
      fi 
   done
}

processDir $PWD
