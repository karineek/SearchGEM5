#./1-wrapper-get-coverage.sh /home/ubuntu/gem5-cov/ /home/ubuntu/gem5-cov/data/gem5-afl-fuzz-cov/data/sliced/seg_5/ 0 5 /home/ubuntu/graphicsfuzz/gfauto/ func-gem5-afl-5.csv lines-gem5-afl-5.csv report-gem5-afl-5.csv
model=$1 # Phi, CodeBooga, Llama, Magicoder, TinyLlama, gpt3.5-new, and gpt3.5-old and with -min extention.


# Fix parameters:
home=/home/debian
exp=$home/experiment/$1/input/
gfauto=$home/graphicsfuzz/gfauto/


./1-wrapper-get-coverage.sh $home $exp 0 5 $gfauto func-gem5-llm-$model.csv lines-gem5-llm-$model.csv report-gem5-llm-$model.csv
