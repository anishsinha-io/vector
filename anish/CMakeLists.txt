add_library(anish src/vector.c include/vector/vector.h include/vector/models.h)
target_include_directories(anish PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)