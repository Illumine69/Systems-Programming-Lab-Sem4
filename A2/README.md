# Assignment 2 : Building projects with makefiles
---
## Commands to implement different application program-

### 1. Make the library
- `make libraries` will create the shared libraries and save the header files in the system default library directory.
- You will be asked to enter system password to save these files in the system library.
### 2. Run the applications
- `make maxchain` will find the longest possible chain of words according to the dictionary you provide.
- `make subwords` will list all (l-1)-letter permutations of the l-length word you give that is present in the dictionary.
### 3. Clean the libraries
- `make clean` will remove all the object, library and the executable files.