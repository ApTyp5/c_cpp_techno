#!/usr/bin/bash




leak_check="valgrind --leak-check=full -q"
input_tests="./tests_in"
output_tests="./tests_out"
test_template="test_"
result_file="./__test_output__.deleteme"
exe="./test.exe"

start_num=1
stop_num=7


for (( i = $start_num; i < $stop_num; i++ ))
do
	echo -n "Test" $i ":"
	$leak_check $exe < $input_tests/$test_template$i > $result_file

	
	if cmp $output_tests/$test_template$i $result_file
	then
		echo -e "\e[32m SUCCESS \e[0m"
	else
		echo -e "\e[31m ERROR \e[0m"
        echo "od -c $result_file:"
        od -c $result_file

        echo "od -c $output_tests/$test_template$i:"
        od -c $output_tests/$test_template$i
	fi
done


