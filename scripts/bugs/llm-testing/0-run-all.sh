inputs=$1 # e.g. /home/ubuntu/experiment-7/

./1-run-diff-test.sh $1/CodeBooga/input
./1-run-diff-test.sh $1/Llama/input
./1-run-diff-test.sh $1/Magicoder/input
./1-run-diff-test.sh $1/Phi/input
./1-run-diff-test.sh $1/TinyLlama/input
./1-run-diff-test.sh $1/gpt3.5-new/input
./1-run-diff-test.sh $1/gpt3.5-old/input
echo ">> Done."
