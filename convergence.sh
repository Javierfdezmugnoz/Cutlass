#!/bin/bash

for file in $1*
	do (cat "${file}";) >> ${1}_square.csv
done
mv ${1}_square.csv ../../../timing_measurements/square/.
