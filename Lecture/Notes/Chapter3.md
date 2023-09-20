<!-- vscode-markdown-toc -->
* 1. [3.1 The Unix File Concept](#TheUnixFileConcept)
		* 1.1. [3.1.1 UNIX File Types](#UNIXFileTypes)
		* 1.2. [3.1.2 Key Features of the Unix File System](#KeyFeaturesoftheUnixFileSystem)
* 2. [3.2 The Unix Filesystem](#TheUnixFilesystem)
		* 2.1. [3.2.1 One root to rule them all](#Oneroottorulethemall)
		* 2.2. [3.2.2 Mounting](#Mounting)
		* 2.3. [3.2.3 Soft Links and Hard Links](#SoftLinksandHardLinks)
* 3. [3.3 Filesystems and Security](#FilesystemsandSecurity)
		* 3.1. [3.3.1 Standar *nix Access Control Lists (ACL)4](#StandarnixAccessControlListsACL4)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc --># Chapter 3: Unix Filesystem Concepts & I/O

## <a name='TheUnixFileConcept'></a>3.1 The Unix File Concept
- Unix file is a *sequence of bytes*
- in *nix systems, everything is modeled as file
  - regular files
  - directories
  - devices
  - pipes
  - network
  - etc...

- Additional Link
  - [Geeks for Geeks - Linux File Hierarchy Structure](https://www.geeksforgeeks.org/linux-file-hierarchy-structure/)
  - [Wikipedia - Filesystem Hierarchy Standard](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard)
  - [Tistory - 리눅스 디렉토리 구조](https://inpa.tistory.com/entry/LINUX-%F0%9F%93%9A-%EB%A6%AC%EB%88%85%EC%8A%A4-%EB%94%94%EB%A0%89%ED%86%A0%EB%A6%AC-%EA%B5%AC%EC%A1%B0)

#### <a name='UNIXFileTypes'></a>3.1.1 UNIX File Types
1. Regular Files
  - Files that contain user/app information 
    - text files
    - binary files
  - OS doesn't know the format of the file

2. Directories
  - A file that contains the names and locations of other files
  - contain a list of file names and pointers to the actual files
  - each directory has two entries
    - `.`: current directory
    - `..`: parent directory

3. Character Special Files/Blcock Special Files
  - represent devices
  - character special files
    - unbuffered data access
    - data is transmitted character by character
    - devices that require simultaneous respond(like keyboard, mouse, etc...)
    - e.g. terminals, printers, networks
  - block special files
    - buffered
    - usually virtualized by OS
    - data is transmitted in blocks
    - e.g. disks

4. FIFOs(named pipe)
  - used for interprocess communication

5. Sockets
  - communication between processes

#### <a name='KeyFeaturesoftheUnixFileSystem'></a>3.1.2 Key Features of the Unix File System
- Design concept: All input and output is handled in a consistent and uniform way
- Elegant mapping of files to devices allows kernel to export simple interface called Unix I/O

**One single file interface to interact with any kind of device(well, almost)**

## <a name='TheUnixFilesystem'></a>3.2 The Unix Filesystem

#### <a name='Oneroottorulethemall'></a>3.2.1 One root to rule them all
- Unix filesystem is a tree structure
  - root("/") directory is the top of the tree which is the only directory that doesn't have a parent directory
  - this is different from Windows
    - Windows has multiple roots
    - e.g. C:\, D:\, etc...
- Each directory only have **one parent** directory
- Then, what about devices?
  
####  <a name='Mounting'></a>3.2.2 Mounting
- Mounting is the process of attaching a filesystem to a directory of another filesystem
  - Usually, link phyiscal devices to directories
- Mounting allows the user to access the files in the mounted filesystem

####  <a name='SoftLinksandHardLinks'></a>3.2.3 Soft Links and Hard Links
- Soft links
  - reference to another file
  - soft links are just like shortcuts in Windows
  - soft links are not the same as the original file
  - soft links can be created across filesystems

- Hard links
  - a file that points to the same inode as another file

##  <a name='FilesystemsandSecurity'></a>3.3 Filesystems and Security

####  <a name='StandarnixAccessControlListsACL4'></a>3.3.1 Standar *nix Access Control Lists (ACL)4
- three kinds of permissions
  - read(r, 4), write(w, 2), execute(x, 1)
- three levels of access control
  - owner, group, other
- modify permissions
  - `chmod` command
  - `chmod 777 file` gives all permissions to all users
  - `chmod 755 file` gives all permissions to owner, read and execute permissions to group and other users


file size of directory is unit of 4k(block)
memory do garbage collection when all files hard link deleted
[shebang(secret of #! /usr/bin/env bash))](https://bcp0109.tistory.com/343)