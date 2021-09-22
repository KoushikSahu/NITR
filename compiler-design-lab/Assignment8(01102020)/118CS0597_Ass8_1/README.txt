This program generates 3-address code of the given source file.
If <some_file>.txt is the input file then the output will be stored in out_<some_file>.txt

To compile:
$ make

To run:
$ ./calc some_file

To clean directory:
$ make clean

EXAMPLES
$ cat small_input.txt
a = b * (c + d)

$ ./calc small_input.txt

$ cat out_small_input.txt
t1 = - b
t2 = c + d
t3 = t1 * t2
a = t3
