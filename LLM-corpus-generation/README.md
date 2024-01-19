# LLM API

There are many API we can use. For the original SSBSE 2023 paper, we utilised Python3 API for GPT 3.5.

There are some other options, documented below.

## OLLAMA API

You can download any hugging face model or use ollama ready to use models.
https://ollama.ai and https://hub.docker.com/r/ollama/ollama.


Install ollama:
```
curl https://ollama.ai/install.sh | sh
```

Check the the version of ollama:
```
ollama --version
```

### ollama models
To pull ready-to-user from ollama DB:
```
nano model2
[copy then this text into the file]
FROM phind-codellama:latest
PARAMETER num_gpu 0
[save and exit]

ollama create ollama_phi_no-gpu -f model2
```
You can find all the models here: https://ollama.ai/library.

To run and use the model in interactive way:
```
ollama run ollama_phi_no-gpu:latest
```
or as a query to use inside other program:
```
ollama run ollama_phi_no-gpu:latest "Give me a short C program only. The code gets to numbers and return the sum of these"
```
or
```
ollama run ollama_phi_no-gpu:latest "Give me a short C program only. The code gets to numbers and return the sum of these" > resultx.txt
```


### Hagging face model and other external models
To use your own or hagging face model:
```
nano model1
[copy then this text into the file]
FROM ./MODELS/deepseek-coder-6.7b-instruct.Q5_K_M.gguf
PARAMETER num_gpu 0
[save and exit]

ollama create deepseek_no-gpu -f model1
ollama run deepseek_no-gpu
```

Say we pull earlier the model, for example:
```
cd MODELS/
wget https://huggingface.co/TheBloke/deepseek-coder-6.7B-instruct-GGUF/resolve/main/deepseek-coder-6.7b-instruct.Q5_K_M.gguf
cd ..
```

To see all models loaded to ollama API:
```
ollama list
```
and we get (for example) this output:
```
NAME                        	ID          	SIZE  	MODIFIED           
deepseek_coder_no-gpu:latest	e2b8aad670cd	4.8 GB	6 seconds ago     	
ollama_phi_no-gpu:latest    	254aa43a6301	19 GB 	About a minute ago	
phind-codellama:latest      	566e1b629c44	19 GB 	About a minute ago	
```
