# Chapter 5: Files and Directories

## 5.1 File Metadata
- data about file
- metadata is stored in file/inode
  - filename store in file
  - rest of metadata store in inode(internal storage unit used by Unix file system)
    - simply, kind of block in disk

![inode structure](/Notes/images/inode_structure.png)

#### 5.1.1 Struct of metadata
- in Unix I/O API, metadata called `stat`
```c
struct stat {
    dev_t           st_dev;             // device
    ino_t           st_ino;             // inode
    mode_t          st_mode;            // protection and file type
    nlink_t         st_nlink;           // number of hard links
    uid_t           st_uid;             // user ID of owner
    gid_t           st_gid;             // group ID of owner
    dev_t           st_rdev;            // device id (if special file)
    off_t           st_size;            // total size, in bytes
    unsigned long   st_blksize;         // preferred blocksize for filesystem I/O
    unsigned long   st_blocks;          // number of 512b blocks allocated
    // high-precision timestamps (precision: nanoseconds; since Linux kernel >=2.6)
    struct          timespec st_atim;   // time of last access
    struct          timespec st_mtim;   // time of last access
    struct          timespec st_ctim;   // time of last status change
    // low-precision timestamps  (precision: seconds; always available)
    time_t          st_atime;           // time of last access
    time_t          st_mtime;           // time of last modification
    time_t          st_ctime;           // time of last status change
};
```
1. st_mode
2. st_uid/st_gid
3. st_size/st_blksize/st_blocks
  - file is sparse if st_size / 512 > st_blocks
  - sparse file: file that has empty space(holes)

          프로그램이 파일의 끝 너머로 파일 오프셋을 옮기고 쓰기 작업을 하면, 파일 중간에 빈 공간이 생긴다.
          이전의 파일 끝과 새로 쓴 바이트들 사이의 이 공간을 파일 구멍(file hole)이라고 한다.
          프로그래밍 관점에서 보면 파일 구멍 속에서도 바이트들이 존재하고, 읽을 시 0으로 채워진 바이트들의 버퍼를 리턴한다.
          하지만 파일 구멍은 디스크 공간을 차지하지 않고 파일 시스템은 나중에 파일 구멍에 데이터가 쓰여질 때 디스크 블록을 할당한다.
          여기서, 디스크 공간 할당에 대해서 블록 할당의 개념을 잘 알아둬야 한다.
          대부분의 파일 시스템이 파일 공간을 블록 단위 (1K / 2K / 4K 등)로 할당하기 때문에
          파일 구멍이 블록 경계에 걸치지 않고 블록 안에 들어간다면, 구멍이 있든 없든 똑같이 블록 하나가 온전히 할당되며
          구멍에 해당되는 부분이 널로 채워질 뿐이다.
          아무튼, File hole이 존재할 수 있기 때문에, 파일의 명목상 크기와 실제 사용하는 디스크 저장소 크기보다 더 클 수 있다.
          따라서, 파일 구멍 중간에 바이트들을 작성하면 파일의 크기는 변하지 않는데 디스크 할당량은 늘어날 수 있다. (빈 공간이 줄어들  수 있다.)
          이는 다시 말해 write 작업으로 파일 크기가 변하지 않아도 디스크 공간 부족으로 실패 하는 일이 있을 수 있는 것이다.
4. ctim[e] vs mtim[e] vs atim[e]

## 5.2 Directories
## 5.3 Kernel File Management