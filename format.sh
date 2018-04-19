gcc average.c -o ave -lm 

sample_files=`echo ./data/foo-`
average_file=`echo ./data/average.dat`

NS=`ls ./data/foo-*.dat | wc -l`      #number of samples
NC=`head -1 ./data/foo-1.dat | wc -w` #number of columns (if single valued)
NL=`cat ./data/foo-1.dat | wc -l`     #number of lines

./ave $sample_files $average_file $NS $NC $NL

exit 

