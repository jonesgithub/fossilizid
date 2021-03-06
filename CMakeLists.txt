PROJECT(Fossilizid)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
ADD_DEFINITIONS(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
ADD_DEFINITIONS(-D___mempool___)

set(portaudio_INCLUDE_PATH ${PROJECT_SOURCE_DIR}//third_party//portaudio//portaudio//include CACHE PATH "Fossilizid include path")
INCLUDE_DIRECTORIES(${portaudio_INCLUDE_PATH})

set(portaudio_LIBS_PATH ${PROJECT_SOURCE_DIR}//third_party//portaudio//portaudio//lib CACHE PATH "Fossilizid include path")
link_directories(${portaudio_LIBS_PATH})

set(speex_INCLUDE_PATH ${PROJECT_SOURCE_DIR}//third_party//speex//speex//include CACHE PATH "Fossilizid include path")
INCLUDE_DIRECTORIES(${speex_INCLUDE_PATH})

set(speex_LIBS_PATH ${PROJECT_SOURCE_DIR}//third_party//speex//speex//lib CACHE PATH "Fossilizid include path")
link_directories(${speex_LIBS_PATH})

set(BOOST_INCLUDE_PATH ${PROJECT_SOURCE_DIR}//third_party//boost CACHE PATH "Fossilizid include path")
INCLUDE_DIRECTORIES(${BOOST_INCLUDE_PATH})

set(BOOST_LIBS_PATH ${PROJECT_SOURCE_DIR}//third_party//boost//libs CACHE PATH "Fossilizid include path")
link_directories(${BOOST_LIBS_PATH})

set(JSON_INCLUDE_PATH ${PROJECT_SOURCE_DIR}//third_party//json//jsoncpp//include CACHE PATH "Fossilizid include path")
INCLUDE_DIRECTORIES(${JSON_INCLUDE_PATH})

set(Fossilizid_include_path ${PROJECT_SOURCE_DIR} CACHE PATH "Fossilizid include path")
INCLUDE_DIRECTORIES(${Fossilizid_include_path})
MESSAGE(STATUS "This is include dir " ${Fossilizid_include_path}) 

set(Fossilizid_lib_path ${PROJECT_BINARY_DIR}/bin/Debug CACHE PATH "Fossilizid lib path")
link_directories(${Fossilizid_lib_path})
MESSAGE(STATUS "This is lib dir " ${Fossilizid_lib_path}) 

set(Fossilizid_bin_path ${PROJECT_BINARY_DIR}/bin CACHE PATH "Fossilizid bin path")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(pool ${Fossilizid_bin_path}/pool)
ADD_SUBDIRECTORY(remoteq ${Fossilizid_bin_path}/remoteq)
ADD_SUBDIRECTORY(reduce ${Fossilizid_bin_path}/reduce)
ADD_SUBDIRECTORY(container ${Fossilizid_bin_path}/container)
ADD_SUBDIRECTORY(context ${Fossilizid_bin_path}/context)
ADD_SUBDIRECTORY(reliablyt ${Fossilizid_bin_path}/reliablyt)
ADD_SUBDIRECTORY(vchat ${Fossilizid_bin_path}/vchat)
ADD_SUBDIRECTORY(third_party ${Fossilizid_bin_path}/third_party)
ADD_SUBDIRECTORY(test ${Fossilizid_bin_path}/test)