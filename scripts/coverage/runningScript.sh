#./1-wrapper-get-coverage.sh /home/ubuntu/gem5-cov/ /home/ubuntu/gem5-cov/data/gem5-afl-fuzz-cov/data/sliced/seg_5/ 0 5 /home/ubuntu/graphicsfuzz/gfauto/ func-gem5-afl-5.csv lines-gem5-afl-5.csv report-gem5-afl-5.csv
op=$1	 # Which option?
model=$2 # Phi, CodeBooga, Llama, Magicoder, TinyLlama, gpt3.5-new, and gpt3.5-old and with -min extention.


# Fix parameters:
home=/home/debian
gfauto=$home/graphicsfuzz/gfauto/

if [ "$op" = "init" ]; then
	exp=$home/experiment/$model/input/
	./1-wrapper-get-coverage.sh $home $exp 0 5 $gfauto func-gem5-llm-$model.csv lines-gem5-llm-$model.csv report-gem5-llm-$model.csv
elif [ "$1" = "cont" ]; then
	exp=$home/experiment/$model/output-uniq/
	./1-wrapper-get-coverage-cont.sh $home $exp 1 5 $gfauto func-gem5-afl-$model.csv lines-gem5-afl-$model.csv report-gem5-afl-$model.csv
elif [ "$op" = "sliced" ]; then
	exp=$home/experiment/$model/split/
	# TODO
	./0-get-coverage.sh /home/ubuntu/gem5-cov/ /home/ubuntu/gem5-cov/data/gem5-afl-fuzz-cov/data/sliced/seg_5/ 0 5 /home/ubuntu/graphicsfuzz/gfauto/ func-gem5-afl-5.csv lines-gem5-afl-5.csv report-gem5-afl-5.csv
else
	bash
fi

# Full models list
# ================
# - CodeBooga
# - Llama
# - Magicoder
# - Phi
# - TinyLlama
# - gpt3.5-new
# - gpt3.5-old
# - CodeBooga-cmin
# - Llama-cmin
# - Magicoder-cmin
# - Phi-cmin
# - TinyLlama-cmin
# - gpt3.5-new-cmin
# - gpt3.5-old-cmin
