Supose N data files named foo-i.dat, i=1, ..., N.

formatted as 
x(1,1) x(1,2) ... x(1,NC) 
x(2,1) x(2,2) ... x(2,NC)
.
.
.
x(NL,1) x(NL,2) ... x(NL,NC).

The script average.c calculates the average and the 
sample standard variation of each column. 

The usage is 
./ave [sample_files] [average_file] [N] [NC] [NL]

where in the example above sample_files = "foo-"

Also see "format.sh"
 
