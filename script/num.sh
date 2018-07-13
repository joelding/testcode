#!/bin/sh

for i in {1..255}
do
#	echo 6C $i
	var=$(printf '%02X' $i)
	echo -e '\t'6C $var
done
