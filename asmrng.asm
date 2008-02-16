
     %include "WIN32N.INC"
     EXTERN ExitProcess
	 IMPORT ExitProcess kernel32.dll
	 EXTERN GetStdHandle
	 IMPORT GetStdHandle kernel32.dll
	 EXTERN WriteFile
	 IMPORT WriteFile kernel32.dll


	 segment .data USE32
		HelloWorld db "Hello assembly world!",0
        ErrorCode dd 0
	 segment .code USE32

	  ..start:
	  push dword STD_OUTPUT_HANDLE ;um STDERR zu benützen geht alternativ STD_ERROR_HANDLE
      call [GetStdHandle]
      push dword 0
	  push dword ebx
	  push dword 12
	  push dword HelloWorld
	  push dword eax ;erhalten durch GetStdHandle oder CreateFile
	  call [WriteFile]
	  ;push dword MB_ICONHAND + MB_OKCANCEL
	  ;push dword HelloWorld
	  ;push dword HelloWorld
	  ;push dword 0
	  ;call [MessageBoxA]

	  push dword ErrorCode
	  call [ExitProcess]
