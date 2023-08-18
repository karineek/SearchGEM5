path="/home/ubuntu/Gem5Testing/data/corpus"

ls -l $path"/afl/"$1".txt" > delme.txt
res1=`echo $?`

ls -l $path"/source/"$1".c" > delme.txt
res2=`echo $?`

ls -l $path"/binary/"$1".c.o.types" > delme.txt
res3=`echo $?`

if [ $res1 -eq 2 ] ; then
   echo ">> Missing $path/afl/$1.txt"
fi

if [ $res2 -eq 2 ] ; then
   echo ">> Missing $path/source/$1.c"
fi

if [ $res3 -eq 2 ] ; then
   echo ">> Missing $path/binary/$1.c.o.types"
fi
