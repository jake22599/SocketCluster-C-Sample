Objective:
- run a win32 console application
- connect to the socket cluster server

Requirements:
- download the SocketCluster sample client for c
https://github.com/sacOO7/socketcluster-client-C
it have 2 external dependencies and the sample client is not configured.
- download libwebsockets library
  files needed:
  - websockets.dll
  - websockets.lib
  - websockets_static.lib
  - libwebsockets.h
  - lws_config.h
- download json-c library
  library sources are not compiled.
  Compile steps:
  - download and install cmake
  - "mkdir build"
  - "cd build"
  - "cmake ."
  - "msbuild "json-c.vcxproj" /m /verbosity:normal /p:OutDir=lib\", 
    if unable to compile open the .sln file and compile using VS
    - compile using the ALL_BUILD target
  files needed:
  - json-c.dll
  - json-c.lib
  - arraylist.h
  - debug.h
  - json.h
  - json_c_version.h
  - json_config.h
  - json_config.h
  - json_inttypes.h
  - json_object.h
  - json_object_iterator.h
  - json_pointer.h
  - json_tokener.h
  - json_util.h
  - linkhash.h
  - printbuf.h
The following dependencies is due to win32 support
- getopt.h and getopt.c
- unistd.h
- pthread-win32
  files needed:
  - pthreadGC2.dll
  - pthreadGCE2.dll
  - pthreadVC2.dll
  - pthreadVCE2.dll
  - pthreadVSE2.dll
  - libpthreadGC2.a
  - libpthreadGCE2.a
  - pthreadVC2.lib
  - pthreadVCE2.lib
  - pthreadVSE2.lib
  - pthread.h
  - semaphore.h
  
VS Project Settings:
- Project Properties > Configuration Properities > C/C++ > General
  Additional Include Directories
  - Arguments to add "lib"
  SDL checks, so to prevent compile errors due to warnings and etc
  - set to NO
- Project Properties > Configuration Properities > C/C++ > Precompilied Headers
  Precompilied Header
  - Not Using Precompiled Headers
- Project Properties > Configuration Properities > Linker
  Input
  - Additional Dependencies: add these options:
    - {path relative from project}/pthreadVC2.lib
	- {path relative from project}/pthreadVCE2.lib
	- {path relative from project}/pthreadVSE2.lib
	- {path relative from project}/json-c.lib
	- {path relative from project}/websockets.lib

	
Notes:
- "hashmap.h" file is missing the following parameters
  - #define MAP_MISSING -3  /* No such element */
	#define MAP_FULL -2 	/* Hashmap is full */
	#define MAP_OMEM -1 	/* Out of Memory */
	#define MAP_OK 0 	/* OK */
- the sample main file is "callback_fun.c"
  It have the main function defined. This file includes "scclient.c" thus the other files do not need to be compiled by the VS.
  "scclient.c" also includes "hashmap_string.c", "hashmap.c", "scclient.h", "json_parser.c" and"parser.c"
	

Versions:
- SocketCluster Client in c
  commit 8537e7c74726e7a9679c7e21f4d711c276111be9
  downloaded on 08/05/2018
- libwebsockets release v3.0.0
  commit eaa935a80adb38b5cc4d09ce06ec987b87dcddfa
  downloaded on 08/05/2018
- json-c release json-c-0.13.1-20180305
  commit 985c46fec39d1d3043f98e8d8cdb9d040131b3bb
  downloaded on 08/05/2018
- pthread-win32 release v-2-9-1-release 
  commit 1389ddcd73f718504669824163aa03552ab483cf
  downloaded on 08/05/2018

References:
https://github.com/SocketCluster/client-drivers
https://github.com/sacOO7/socketcluster-client-C
https://github.com/warmcat/libwebsockets
https://github.com/json-c/json-c
https://cmake.org/download/
https://gist.github.com/ashelly/7776712
https://stackoverflow.com/questions/341817/is-there-a-replacement-for-unistd-h-for-windows-visual-c
https://github.com/GerHobbelt/pthread-win32/releases


Documentation last updated:
8th of May 2018
