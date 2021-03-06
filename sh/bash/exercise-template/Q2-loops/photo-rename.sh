#!/bin/bash
#start looping
    #change the file descriptor
    BIFS=$IFS
    IFS=$'\n'
ls *.jpg 2> /dev/null
if [ $? -ne 0 ];then
    echo "There are no jpegs here, the program will now exit"
    exit 1
fi
for i in `ls *jpg` #ignore files not following the pattern
do
    #only pick the images that satisfy this pattern
    
    if [[ "$i" =~ [0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9].*\.jpg ]] ; then
        day=${i:0:2}
        month=${i:2:2}
        year=${i:4:4}
        any=`echo $i|cut -f1 -d'.'`
        any=`expr "$any" : '[0-9]*\(.*\)'`
        if [ ! -z "$any" ];then
            newName="$year-$month-$day-$any.jpg"
        else
            newName="$year-$month-$day.jpg"
        fi
        eval "mv '$i' '$newName'"
        echo "Renaming '$i' ->  '$newName'"
    fi
done

    IFS=$BIFS
