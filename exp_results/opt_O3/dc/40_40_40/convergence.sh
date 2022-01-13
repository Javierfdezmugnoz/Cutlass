#!/bin/bash

for file in $1*
	do (cat "${file}";) >> ${1}_${0}.csv
done
