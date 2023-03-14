set(GLAD_DIR "${SUBM_DIR}/GLAD")
add_subdirectory("${GLAD_DIR}/cmake")
glad_add_library(glad STATIC REPRODUCIBLE API gl:core=4.6)
target_link_libraries(${PROJECT_NAME} glad)
target_include_directories(${PROJECT_NAME} PRIVATE "${GLM_DIR}")