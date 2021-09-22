#! /bin/bash

echo "Enter day of week (Number between 1 and 7 inclusive)"
read day

case $day in
	1) echo "Monday" ;;
	2) echo "Tuesday" ;;
	3) echo "Wednesday" ;;
	4) echo "Thursday" ;;
	5) echo "Friday" ;;
	6) echo "Saturday" ;;
	7) echo "Sunday" ;;
	*) echo "Invalid number entered" ;;
esac
