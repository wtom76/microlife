cmake_minimum_required(VERSION 3.0.0)
project(microlife VERSION 0.1.0)

message(STATUS "system: ${CMAKE_SYSTEM}")
message(STATUS "build_type: ${CMAKE_BUILD_TYPE}")
message(STATUS "paths:")
message(STATUS " - ${CMAKE_INSTALL_PREFIX}")
message(STATUS " - ${PROJECT_SOURCE_DIR}")
message(STATUS " - ${PROJECT_BINARY_DIR}")
message(STATUS)
message(STATUS "compiler:")
message(STATUS " - ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - ${CMAKE_CXX_COMPILER}")
message(STATUS)
message(STATUS "cmake:")
message(STATUS " - ${CMAKE_VERSION}")
message(STATUS " - ${CMAKE_COMMAND}")
message(STATUS " - ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS " - ${CMAKE_GENERATOR}")
message(STATUS " - ${CMAKE_BUILD_TOOL}")
message(STATUS)

include(CTest)
enable_testing()

find_package(SFML
	COMPONENTS
		system window graphics
)

add_executable(microlife
	pch.h
	entity.h
	config.h config.cpp
	render.h render.cpp
	field.h field.cpp
	fauna/population.h fauna/population.cpp
	fauna/creature.h fauna/creature.cpp
	environment/obstacle.h
	environment/obstacle_cont.h environment/obstacle_cont.cpp
	main.cpp
)

target_link_libraries(microlife
	sfml-graphics
)

target_precompile_headers(microlife
	PUBLIC
		pch.h
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
