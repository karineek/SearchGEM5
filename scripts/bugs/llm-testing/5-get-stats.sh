InitLogger=$1
logger=$2
model=$3

echo "File-1 contents are present in File-2"
grep -A1 "$model" $InitLogger | grep  "File-1 contents are present in File-2" | wc -l

echo "Both failed. Skip"
grep -A1 "$model" $InitLogger | grep "Both failed. Skip" | wc -l

echo "False simulation: Simulation error, NATIVE OK"
grep -A1 "$model" $InitLogger | grep "False simulation: Simulation error, NATIVE OK" | wc -l

echo "False simulation: Simulation OK, NATIVE error"
grep -A1 "$model" $InitLogger | grep "False simulation: Simulation OK, NATIVE error" | wc -l

echo "DIFF TESTING"
grep -A1 "$model" $InitLogger | grep "DIFF TESTING" | wc -l

echo "Run to compare"
grep -a "command line:" $logger | grep "$model" | wc -l
