# Abstract-VM

Abstract-VM is a C++ pet-project from 42 course (task is available [here](abstract-vm.en.pdf)).

## About

Abstract-VM is a stack-based VM able to interpret simple pseudo-ASM language.
As any pet project Abstract-VM is written to get some practice upgrade some skills.
In tis project were used some patterns: Factory Method, Singletone
and technologies: flex(lex), yacc(bison).

## Installation

```bash
make
```

## Usage

```bash
./avm script.avm
```

## Syntax

```asm
instruction dataType(value)
intruction
```

## Grammar

```goyacc

S := INSTR [SEP INSTR]* #

INSTR := 
    push VALUE
    | pop
    | dump
    | assert VALUE
    | add
    | sub
    | mul
    | div
    | mod
    | print
    | exit
   
VALUE :=
    int8(N)
    | int16(N)
    | int32(N)
    | float(Z)
    | double(Z)

N := [-]?[0..9]+
Z := [-]?[0..9]+.[0..9]+

SEP :='\n'+

```

[AVMLexer.l](Grammar/AVMLexer.l) / [AVMGrammar.y](Grammar/AVMGrammar.y)

## Example

```asm

; ------------------
; - HelloWorld.avm -
; ------------------
push int8(72)	;H
printX
push int8(101)	;e
print
push int8(108)	;l
print
print
push int8(111)	;o
print
push int8(44)	;,
print
push int8(32)	;' '
print
push int8(119)	;w
print
push int8(111)	;o
print
push int8(114)	;r
print
push int8(108)	;l
print
push int8(100)	;d
print
push int8(33)	;!
print
push int8(10)	;\n
print
exit

```
```bash
./AVM hello.avm | cat -e
Hello, World!$
```

### TODO in README.md
* what for
* how to use
* available features
* script exmaples
* design


## License
[MIT](https://choosealicense.com/licenses/mit/)
