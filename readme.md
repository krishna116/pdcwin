# pdcwin

Public domain curses library for windows console application. it is extracted from [PDCursers](https://github.com/wmcbrine/PDCurses).  

Features:  
- Only contains windows console branch.  
- Make source code to include relative path for source code.  
- Repack with cmake.  

version: 3.9  
license: public domain  

## How to build it.
```
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=<path-to-install-directory>
cmake --build build
cmake --install build
```

## References.

https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/  
https://jbwyatt.com/ncurses.html  