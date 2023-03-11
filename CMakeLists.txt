cmake_minimum_required(VERSION 3.7)

project(HelloOpenGL CXX)

add_definitions(-DUNICODE)
add_definitions("/MP")
set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/Source")
set(SUBM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Submodules")
set(DEPS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies")

file(GLOB_RECURSE SRC SRC_DIR
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.hpp")

add_executable(${PROJECT_NAME} ${SRC})

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")

# GLAD
set(GLAD_DIR "${SUBM_DIR}/GLAD")
add_library(GLAD STATIC IMPORTED)
set_target_properties(GLAD PROPERTIES
  IMPORTED_LOCATION "${DEPS_DIR}/GLAD/Debug/glad.lib"
  INTERFACE_INCLUDE_DIRECTORIES "${DEPS_DIR}/GLAD/include"
)
target_link_libraries(${PROJECT_NAME} GLAD)

# GLFW
set(GLFW_DIR "${SUBM_DIR}/GLFW")
add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES
  IMPORTED_LOCATION "${DEPS_DIR}/GLFW/src/Debug/glfw3.lib"
  INTERFACE_INCLUDE_DIRECTORIES "${GLFW_DIR}/include"
)
target_link_libraries(${PROJECT_NAME} GLFW)

# GLM
set(GLM_DIR "${SUBM_DIR}/GLM")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLM_DIR}")
