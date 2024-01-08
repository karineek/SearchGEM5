# AFL Custom mutators for fuzzing gem5

The mutators are in cm-gem5.c file. 

To build the three mutators supported (as shared):
```
```

We currently override:

The current version of AFL++ we use, allows us to override also:
```
[*] optional symbol 'afl_custom_fuzz_count' not found.
[*] optional symbol 'afl_custom_post_process' not found.
[*] optional symbol 'afl_custom_init_trim' not found.
[*] optional symbol 'afl_custom_trim' not found.
[*] optional symbol 'afl_custom_post_trim' not found.
[*] optional symbol 'afl_custom_havoc_mutation' not found.
[*] optional symbol 'afl_custom_havoc_mutation_probability' not found.
[*] optional symbol 'afl_custom_queue_get' not found.
[*] optional symbol 'afl_custom_splice_optout' not found.
[*] optional symbol 'afl_custom_fuzz_send' not found.
[*] optional symbol 'afl_custom_queue_new_entry' not found
[*] optional symbol 'afl_custom_describe' not found.
```
