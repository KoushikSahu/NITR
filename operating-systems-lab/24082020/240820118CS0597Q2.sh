#! /bin/bash
logname=`whoami`

# touch myFile

directory=`pwd`
echo "Searching in $directory"

echo "Before running shell script content of pwd is"
echo `ls`

if [ -e myfile ]
then
	mv myfile myfile_$logname
else
	echo "File doesn't exist"
fi

echo "After running shell script content of pwd is"
echo `ls`
