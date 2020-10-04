# Challenge 001 - Make schedule for classroom lectures using minimum number of rooms

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required; and print the schedule for each room.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2 rooms; Room #1: (0 - 50), (60 - 150); Room #2: (30 - 75)

# Compile on linux

$ cd ..

$ mkdir build-001-make-schedule

$ cd build-001-make-schedule

$ qmake -o Makefile ../001-make-schedule/001.pro

$ make

Tested with qmake 3.1 (Qt 5.9.5) and g++ 7.5.0
