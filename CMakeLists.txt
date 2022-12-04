cmake_minimum_required(VERSION 3.0.0)
project(microlife VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML
	COMPONENTS
		system window graphics
)

add_executable(microlife
	main.cpp render.cpp render.h
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
