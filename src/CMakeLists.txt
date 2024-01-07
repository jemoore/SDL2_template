# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Disable useless warnings
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.13.0")
	cmake_policy(SET CMP0077 NEW)
endif()

# Disable useless compiler warnings
if (MSVC)
	add_compile_options(/wd4068) # Disable unknown pragma warning.
	add_compile_options(/wd4996) # Disable unsecure function warnings. (e.g. sprintf())
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCE_FILES
	main.cpp
)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)
