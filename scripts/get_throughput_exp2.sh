#!/bin/bash

function f1 {
  for i in {1..8}; do
    cd $i
    pwd
    ls -l */output_*/default/queue/id:*,src:* | wc -l
    cd ..
  done
}

## Start script
for prefix in CodeBooga Llama Magicoder Phi TinyLlama gpt3.5-new gpt3.5-old; do
  for dir in output-2-$prefix-{1,5,6,7,8}; do
    cd "$dir"
    f1
    cd ..
  done

  for dir in output-2-$prefix-cmin-{1,5,6,7,8}; do
    cd "$dir"
    f1
    cd ..
  done
done
