#/bin/bash
files=$(ls -al|awk {'print $5'})
for file in $files
do
		sum=$[sum+file]
done
echo $sum"	kb"
