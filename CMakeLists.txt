cmake_minimum_required(VERSION 3.12)
project(SobelProject)

# Set C++ version
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Add your source files
set(SOURCE_FILES
    src/main.cpp
    src/Sobel.cpp
)

# Add your header files
set(HEADER_FILES
    src/Sobel.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Link with OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
