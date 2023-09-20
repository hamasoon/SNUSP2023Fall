# Chapter 1:  A Tour of Computer Systems

## 1.1 Information is Bits + Context
- All information in a system is represented as a bunch of bits. Different contexts interpret the bits differently.(**Type**)

## 1.2 Programs Are Translated by Other Programs into Different Forms
- To run a program in system, we need to translate it into a low-level machine language that the hardware can execute.
- Usually this process divide into 4-stages
  - Preprocessor: expand the source c-program according to the `#` command(directive).
    - ex) `#include`, `#define`
    - after this stage, create new source file with `.i` extension.
  - Compiler: translate the `.i` file into assembly-language file.(`.s` extension file)
  - Assembler: translate the assembly-language file into relocatable object file.(`.o` extension file)
    - From here, result saved in binary format.
  - Linker: combine the relocatable object file(`.o`) with library function code to generate the executable object file.
    - ex) `printf` function is in `printf.o` file. so, link program(ld) link `printf.o` file with executable object file.
    - after this stage, create new file with executable object file(different extension by system)

## 1.3 It Pays to Understand How Compilation Systems Work

#### Understanding how compilation system works is important because it affects the performance of the program.

1. Optimization
  - We don't need to understand the details of the compiler, but we need to understand the how the compiler translate the source code into machine code.
  - ex) `x = x * 4;` -> `x = x << 2;`
  - ex) `switch` vs `if-else`
    - `switch` is faster than `if-else` because `switch` use jump table.
    - `if-else` is faster than `switch` when the number of cases is small.
  - ex) `for` vs `while`
  - ex) `pointer` vs `array`

2. Understanding link-time errors
  - difference between `static` variable and `gloabl` variable.
  - what happen we declare same global variable in different file?

3. Avoid security holes
  - buffer overflow
  - format string attack
  - how data and control information is stored in stack.

## 1.4 Processors Read and Interpret Instructions Stored in Memory

#### 1.4.1 Hardware Organization of a System
1. Buses : electrical cable that transfer data(as unit of `word`(32bits, 64bits)) between components.
2. I/O Devices
3. Main Memory: store program's instruction and data while program run.
4. Processor: execute program
  - Load: read data from memory to register
  - Store: write data from register to memory
  - Operate: perform arithmetic or logical operation
  - Jump: modify the program counter to control the flow of execution.

#### 1.4.2 Running the Hello Program
1. Shell read the command from keyboard and execute the program.
  - Then store the command as a string in register and store in main memory.
2. Load designated program from disk to main memory.
  - 'hello world\n' also stored in main memory.
3. Processor execute the program by reading the instruction from main memory.
  - 'hello world\n' inside main memory is loaded into register and print to screen.

## 1.5 Caches Matter
- I/O instruction is very slow compared to processor speed.
- So, we use cache to reduce the average memory access time.(**Locality**)
  - Temporal Locality: If an item is referenced, it will tend to be referenced again soon.
  - Spatial Locality: If an item is referenced, items whose addresses are close by tend to be referenced soon.

## 1.6 Storage Devices Form a Hierarchy

## 1.7 The Operating System Manages the Hardware
- Operating System is a program that link software appilcation with the hardware system.
  - All software run on top of the operating system.

- Purpose of Operating System
  - to protect the hardware from misuse by runaway applications
  - to provide applications with simple and uniform mechanisms for manipulating complicated and often wildly different low-level hardware devices.

#### 1.7.1 Processes
- Operating System deceive each running program into thinking that it has exclusive use of the hardware.
  - It make the program think that it has its own processor, its own memory, and its own I/O devices.
- Processor execute instruction by switching among processes.
  - this is called as **context switching**
    - context: the current state of the process.(PC, register, stack pointer, main memory data)

#### 1.7.2 Threads
- Parallel execute unit that share same context of process

#### 1.7.3 Virtual Memory

#### 1.7.4 Files

    추상화 결과
    프로세스 : 프로세서, 메인 메모리, 입출력장치 모두의 추상화 결과
    가상 메모리 : 메인 메모리와 디스크 입출력 장치의 추상화
    파일 : 입출력장

## 1.8 Systems Communicate with Other Systems Using Networks

## 1.9 Important Themes

#### 1.9.1 Amdahl's Law
- $\alpha$ = fraction of time that the part is active
- $k$ = speedup factor
$T_{new } = (1-\alpha)T_{old} + (\alpha T_{old})/k = T_{old}((1-\alpha) + \alpha / k)$ : Improved time
$S = \frac{1}{(1-\alpha) + \alpha / k}$ : Improved ratio

#### 1.9.2 Concurrency and Parallelism
- Thread-level concurrency: multiple threads of control executing in a single processor.
- Instruction-level parallelism: multiple instructions from a single thread executing at the same time.

#### 1.9.3 The Importance of Abstractions in Computer Systems

## 1.10 Summary
1. 컴퓨터 내의 정보는 비트들의 그룹으로 표시
2. 컴파일러와 링커에 의해 바이너리 실행파일들로 번역
3. 프로세서는 메인 메모리에 저장된 바이너리 인스트럭션을 읽고 해석
4. 컴퓨터는 대부분의 시간을 메모리, 입출력장치, CPU 레지스터 간에 데이터를 복사하고 쓰는 데 사
용
5. 위와 같은 이유로 시스템의 저장장치들은 계층구조 형성
6. 운영체제 커널은 응용프로그램과 하드웨어 사이에서 중간자 역할 수행
7. 네트워크는 컴퓨터 시스템이 서로 통신할 수 있는 방법 제공