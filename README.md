# Ascii file Writer & Reader

```sh
$ git clone https://github.com/Pr0xe/ascii_file_reader.git
$ cd ascii_file_reader
$ make 
```
### usage 
* -f to add word in file 
* -p to print it decoded or encoded 
==================================================================================
* -f file.txt word    -word will be convert from plain text to ascii
* -p file.txt encoded -(encoded) will print file as it is. Full of ascii words
* -p file.txt decoded -(decoded) will print file translated to plain text

```sh

$ ./reader -f file.txt word 
or
$ ./reader –f file.txt word1 –f file.txt word2 –p file.txt decoded
or
$ ./reader –f file.txt word1 –p file.txt decoded
