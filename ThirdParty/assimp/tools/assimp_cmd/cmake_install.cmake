# Install script for directory: /Users/lukascardot-goyette/Downloads/assimp-3.1.1/tools/assimp_cmd

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-bin")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/lukascardot-goyette/GitHub/COMP_371_3D_Space_Shooter/ThirdParty/assimp/tools/assimp_cmd/assimp")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/assimp" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/assimp")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/lukascardot-goyette/GitHub/COMP_371_3D_Space_Shooter/ThirdParty/assimp/code/libassimp.3.dylib" "/usr/local//libassimp.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/assimp")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/lukascardot-goyette/GitHub/COMP_371_3D_Space_Shooter/ThirdParty/assimp"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/assimp")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/lukascardot-goyette/GitHub/COMP_371_3D_Space_Shooter/ThirdParty/assimp/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/assimp")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/assimp")
    endif()
  endif()
endif()

