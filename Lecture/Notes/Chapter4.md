# Chapter 4: Direct and Buffered I/O

## 4.1 Unix I/O
- Interface of *nix system's kernel
  - Lowest level of I/O
  - Implemented with system call

- Design concept: one standardized, general interface to access files of any type
  - all input and output is handled in a consistent and uniform way!
  - One single file interface to interact with any kind of device

#### 4.1.1 File
- File abstraction
  - open file is identified by a **file descriptor**
  - Each open file has an internal pointer pointing to the current position in the file
    - read/write use this pointer to determine where to start or advance

- File descriptors is basically index of **file descriptor table**
  - **file descriptor table** is table of **file table**
  - Basic fd
    - 0: STDIN_FILENO   standard input
    - 1: STDOUT_FILENO  standard output
    - 2: STDERR_FILENO  standard error
    - this default fd's are connect with terminal

#### 4.1.2 Unix I/O API
1. **open** : `int open(const char *pathname, int flags(, mode_t mode));`
  - arguments
    - pathname: file path
    - flags: 
      - O_RDONLY: read only
      - O_WRONLY: write only
      - O_RDWR: read and write
      - O_APPEND: append to end of file on each write
      - O_CREAT: create file if it doesn't exist
      - O_EXCL: with O_CREAT, fail if file already exists
      - etc...(check `man 2 open`)
    - mode: file permission
      - S_IRUSR: read permission, owner
      - S_IWUSR: write permission, owner
      - S_IXUSR: execute permission, owner
      - S_IRGRP: read permission, group
      - S_IWGRP: write permission, group
      - S_IXGRP: execute permission, group
      - S_IROTH: read permission, other
      - S_IWOTH: write permission, other
      - S_IXOTH: execute permission, other
  - return
    - success: fd(start from 3)
    - fail: -1
  - usage example
  ```c
  int fd;

  if ((fd = open("/etc/hosts", O_RDONLY, IRUSR|S_IWUSR)) < 0) {
    perror("Cannot open file");
    exit(EXIT_FAILURE);
  }
  ```
2. read: `ssize_t read(int fd, void *buf, size_t count);` & write: `ssize_t write(int fd, const void *buf, size_t count);`
  - arguments
    - fd: file descriptor
    - buf: buffer that holds data
    - count: number of bytes to read/write
  - return
    - success: number of bytes read/written
      - short count: if retval < count
        - Encountering EOF (end-of-file) on reads
        - Filesystem full on write
        - Reading text lines from a terminal
        - Reading and writing network sockets or Unix pipes
        - Interrupts and signals sent to the process
    - fail: < 0
  - usage example
  ```c
  if ((nbytes = write(fd, buf, sizeof(buf))) < 0) {
    perror("Cannot write to file");
    exit(EXIT_FAILURE);
  }

  ```
3. seek
  - 
4. close: `int close(int fd);`
  - arguments
    - fd: file descriptor
  - return
    - success: 0
    - fail: -1
  - usage example
  ```c
  if ((retval = close(fd)) < 0) {
    perror("Cannot close file");
    exit(EXIT_FAILURE);
  }
  ```
1. remove(slighly different from other I/O API)
  - 


## 4.2 Standard I/O

## 4.3 Interaction of Standard I/O with Unix I/O