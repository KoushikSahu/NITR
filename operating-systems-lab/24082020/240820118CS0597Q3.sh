#! /bin/bash

echo "Enter 10 numbers: "
read -a arr

cnt=0

for i in ${arr[*]}
do
	cnt=`expr $cnt + 1`
done

tmp=${arr[0]}
if [ $cnt = 10 ]
then
	for idx in 1 2 3 4 5 6 7 8 9
	do
		if [ ${arr[$idx]} -le $tmp ]
		then tmp=${arr[$idx]}
		fi
	done
	echo "Smallest number is: "
	echo $tmp
else
	echo "Count of numbers enterred is not equal to 10!"
fi
