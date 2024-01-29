echo "OLD"
grep "if (argc !=" /home/ubuntu/Gem5Testing/data/afl/$1.c
res=`echo $?`
echo $res

echo "NEW"
grep "if (argc !=" /home/ubuntu/Gem5Testing/data/corpus/source/$1.c
res1=`echo $?`
echo $res1

echo "Experiments"
grep "if (argc !=" /home/ubuntu/experiment-4/binary/source/$1.c
res2=`echo $?`
echo $res2

if [ $res1 -eq 1 ] || [ $res1 -eq 2 ]; then
   if [ $res -eq 0 ] ; then
     cp /home/ubuntu/Gem5Testing/data/afl/$1.c /home/ubuntu/Gem5Testing/data/corpus/source/
   else
     if [ $res2 -eq 0 ] ; then
	cp /home/ubuntu/experiment-4/binary/source/$1.c /home/ubuntu/Gem5Testing/data/corpus/source/
     else
	rm /home/ubuntu/Gem5Testing/data/corpus/source/$1.c
     fi
   fi
fi
