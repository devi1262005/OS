#!/bin/bash
echo "Using for loop:"
for i in {1..5}
do
  echo $i
done

echo "Using while loop:"
counter=1
while [ $counter -le 5 ]
do
  echo $counter
  ((counter++))
done
