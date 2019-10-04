#!/bin/bash

input_tests="./test_in"
output_tests="./tests_out"
test_template="test_"
result_file="./__test_output__.deleleme"
exe="./test.exe"

start_num=1
stop_num=7


for (( i = $start_num; i < $stop_num; i++ ))
do
	echo -n "Test " $i ":"
	$exe < $input_tests/$test_template$i > $result_file

	if $(cmp $output_tests/$test_template$i $result_file) 
	then
		echo -e "\e[32m SUCCESS [0m"
	else
		echo -e "\e[31m ERROR [0m"
	fi
done

