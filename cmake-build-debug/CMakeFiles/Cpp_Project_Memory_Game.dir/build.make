# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = Y:\Documents\GitHub\CPP-Project-Memory-Card-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Cpp_Project_Memory_Game.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Cpp_Project_Memory_Game.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make

CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\main.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\main.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\main.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.obj: ..\player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/player.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\player.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/player.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\player.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/player.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\player.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.obj: ..\reward.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/reward.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\reward.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/reward.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\reward.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/reward.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\reward.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.obj: ..\card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/card.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\card.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/card.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\card.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/card.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\card.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.obj: ..\board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/board.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\board.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/board.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\board.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/board.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\board.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.obj: ..\carddeck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/carddeck.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\carddeck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/carddeck.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\carddeck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/carddeck.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\carddeck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.obj: ..\game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/game.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\game.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/game.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\game.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/game.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\game.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.obj: ..\rules.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/rules.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\rules.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/rules.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\rules.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/rules.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\rules.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.obj: ..\rewarddeck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/rewarddeck.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\rewarddeck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/rewarddeck.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\rewarddeck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/rewarddeck.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\rewarddeck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.obj: CMakeFiles\Cpp_Project_Memory_Game.dir\flags.make
CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.obj: ..\deck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Cpp_Project_Memory_Game.dir/deck.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.obj /FdCMakeFiles\Cpp_Project_Memory_Game.dir\ /FS -c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\deck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cpp_Project_Memory_Game.dir/deck.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\deck.cpp
<<

CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cpp_Project_Memory_Game.dir/deck.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.s /c Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\deck.cpp
<<

# Object files for target Cpp_Project_Memory_Game
Cpp_Project_Memory_Game_OBJECTS = \
"CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.obj" \
"CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.obj"

# External object files for target Cpp_Project_Memory_Game
Cpp_Project_Memory_Game_EXTERNAL_OBJECTS =

Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\main.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\player.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\reward.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\card.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\board.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\carddeck.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\game.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\rules.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\rewarddeck.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\deck.cpp.obj
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\build.make
Cpp_Project_Memory_Game.exe: CMakeFiles\Cpp_Project_Memory_Game.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Cpp_Project_Memory_Game.exe"
	"C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Cpp_Project_Memory_Game.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Cpp_Project_Memory_Game.dir\objects1.rsp @<<
 /out:Cpp_Project_Memory_Game.exe /implib:Cpp_Project_Memory_Game.lib /pdb:Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\Cpp_Project_Memory_Game.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Cpp_Project_Memory_Game.dir\build: Cpp_Project_Memory_Game.exe

.PHONY : CMakeFiles\Cpp_Project_Memory_Game.dir\build

CMakeFiles\Cpp_Project_Memory_Game.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cpp_Project_Memory_Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Cpp_Project_Memory_Game.dir\clean

CMakeFiles\Cpp_Project_Memory_Game.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" Y:\Documents\GitHub\CPP-Project-Memory-Card-Game Y:\Documents\GitHub\CPP-Project-Memory-Card-Game Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug Y:\Documents\GitHub\CPP-Project-Memory-Card-Game\cmake-build-debug\CMakeFiles\Cpp_Project_Memory_Game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Cpp_Project_Memory_Game.dir\depend

