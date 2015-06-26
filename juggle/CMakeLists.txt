PROJECT(juggle)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 

file(GLOB interface_head_file ./interface ./interface/*.h)
file(GLOB service_head_file ./service ./service/*.h)

AUX_SOURCE_DIRECTORY(./service service_SRC)

SET(header_files
    ${interface_head_file}
    ${service_head_file}
)


SET(SRC_LIST 
    ${service_SRC}
)

ADD_LIBRARY(juggle ${SRC_LIST} ${header_files})

file(GLOB pluginjson_head_file ./plugin/json ./plugin/json/*.h)

AUX_SOURCE_DIRECTORY(./plugin/json pluginjson_SRC)

ADD_LIBRARY(jugglejsonplogin ${pluginjson_SRC} ${pluginjson_head_file})
