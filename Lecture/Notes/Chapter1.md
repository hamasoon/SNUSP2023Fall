# Chapter 1: Introduction to System Programming

## 1.1: Hardware Organization
- Buses
- Main Memory
- I/O devices
- Processor
  
#### Program Execution
- Application execute under the assumption they run **exclusively** on the hardware(**Concept of Process**)
  - private memory(virtual memory)
  - private resources(CPU, GPU, all the execution resources)
  - uninterrupted by other devices(disk, network)

- Operating system offer this virtualized enviorment to application

## 1.2: Opearting System

#### Purpose of Operating Systme
- to protect the hardware from misuse by buggy/malicious applications
- to provide applications with simple and uniform mechanisms for manipulating hardware devices.
  - Simply, offer virtualized enviorment

#### Virtualization
- **Process** : Abstraction of program
- **(Thread)**
- **Virtual Memory** : Abstraction of physical main memory
- **Files** : Abstraction of extern physical storage

## 1.3: System Software
- Purpose: Software enabling users to interact with the computer system
- Access hardware how?: Controls and manages the hardware
- Interacts with?: interacts with hardware directly
- Programming languages?: C, Assembly, (maybe rust)
- Machine dependent?: Yes
- Fault tolerance?: No, lead to catastrophic failure
- Include: kernel, (assembler, compiler, linker), (inspection, disk checking and defragmenting)

## 1.4: System Programming
