# note

## program windows

### line separator

``` txt
do not use "\n" use "\r\n"
```

### file encoding

``` txt
source encoding: "UTF-8 with BOM" or "UTF-16 LE" or "ANSI"(outdated)

input encoding: "UTF-16 LE" or "ANSI"(outdated)
```

### win32libs

``` txt
kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
```

## cmake enable mfc

cmake

``` cmake
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 1)  
```

C/C++

``` C++
#define _AFXDLL
#pragma comment(linker,"/ENTRY:wWinMainCRTStartup") 
```

## linux on win

### arch init

bash

``` bash
rm -r /etc/pacman.d/gnupg/
pacman-key --init
pacman-key --populate msys2

pacman-key --init
pacman-key --populate archlinux
```

### wsl default user

reg

``` reg
HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss\{???}
DefaultUid
```

## mysql

cmd

``` batch
mysqld.exe --console --default-time-zone="+8:00"
```
