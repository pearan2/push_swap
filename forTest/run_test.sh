#!bin/bash

INPUT=$1
NUMBER=$2
SUM=0
MAX=0
SET=$(seq 0 $1)
`clang++ main.cpp -o for_test`
cd ..
make re
cd -
for i in $SET
do
	./for_test $NUMBER > test_number
	args=`cat test_number`
	../push_swap $args > solve
	result=`../checker $args < solve`
	if [ "$result" = "OK" ]; then
		solve_wl=`cat solve | wc -l`
		echo "test $i passed >> $solve_wl"
		SUM=`expr $SUM + $solve_wl`;
		if [ $solve_wl -gt $MAX ]; then
			MAX=$solve_wl
		fi
	else
		echo "can't pass test!"
		break
	fi
done
SUM=`expr $SUM / $i`

echo "AVG >> $SUM      MAX >> $MAX"
cd ..
make fclean
cd -