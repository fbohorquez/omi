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
            # echo ${FILE/.dia/.svg}
            # dia -e ${FILE/.dia/.svg} -t svg $FILE
            # inkscape ${FILE/.dia/.svg} --export-png=${FILE/.dia/.png}
            cp $FILE /home/franj/projects/omi.svn/doc/trunk/class/
         fi
      fi 
   done
}

processDir $PWD
