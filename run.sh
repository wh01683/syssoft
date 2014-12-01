#!/bin/bash

# Bash file to easily compile and run virtual memory page replacement project
# Group 1: Trent Holliday, Jared Baker, Robert Howerton, Denzel Kent
files=`ls *.cpp | grep -v virtual`
if [[ $files ]];then
	echo "Compiling " $files
	g++ -c $files
else
	echo "ERROR: .cpp files not found"
fi
mainFile=`ls virtualPaging.cpp`
if [[ $mainFile ]];then
	g++ -o virtualPaging.out -O $mainFile
	./virtualPaging.out
	exit $?
else
	echo "ERROR: virtualPaging.cpp not found"
fi

exit $?