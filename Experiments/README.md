# Experiments

## LLM-based test case generation

TODO

## Filtering Non-crashing Tests

We test per test if it crashes AFL++, and discard it if so/

TODO

## Prepare to Fuzz

You need to select a set, and copy it to a folder dedicated to the experiment. Then run:
```
tar -xvf  gpt3.5-old.tar.gz 
cd gpt3.5-old/
cd input/
sed -i "s:/home/ubuntu/sets/gpt3.5-old/sort/data:/home/ubuntu/experiment-7/gpt3.5-old/binary:g" *.txt
```
