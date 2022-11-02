# Compile
gcc -o ./cache/$1.out ../$1
# Run
while read line; do
    line_arr=(${line//,/ }) # split the line by space ref: https://stackoverflow.com/questions/918886/how-do-i-split-a-string-on-a-delimiter-in-bash

    exp_out=${line_arr[${#line_arr[@]}-1]} #last element ref : https://unix.stackexchange.com/questions/198787/is-there-a-way-of-reading-the-last-element-of-an-array-with-bash
    output=$(echo "$line" | ./cache/$1.out)

    # compare the output with the expected output
    echo "Expected output: $exp_out Output: $output"
    if [ "$output" = $exp_out ]; then
        echo "Test passed"
    else
        echo "Test failed"
    fi
done < ./cases/$2