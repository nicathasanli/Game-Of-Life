cmake_minimum_required(VERSION 3.10.2)
project(GameOfLifeStep2 LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)

find_package(Doxygen)

if(DOXYGEN_FOUND)

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

    add_custom_target(docs
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/Docs/html/index.html  
    )
endif(DOXYGEN_FOUND)



set (FILES_TAR_GZ "${CMAKE_CURRENT_SOURCE_DIR}")

add_custom_target(dist
    COMMAND ${CMAKE_COMMAND} -E tar "cfvz" "GameOfLifeStep2.tar.gz" "${FILES_TAR_GZ}"
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/build/GameOfLifeStep2.tar.gz
        ${CMAKE_CURRENT_SOURCE_DIR}
    )


add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PUBLIC game console)