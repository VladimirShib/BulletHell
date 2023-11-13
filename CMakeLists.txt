cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(yorha-game)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics audio system REQUIRED)

add_executable(app
${CMAKE_CURRENT_SOURCE_DIR}/game/src/headers.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/game.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/game.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/screens.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/screens.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/levels.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/levels.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/maps.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/maps.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/player.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/player.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/enemies.h
${CMAKE_CURRENT_SOURCE_DIR}/game/src/enemies.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/src/collision.cpp
)

target_include_directories(app PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app PUBLIC cxx_std_17)
target_compile_definitions(app PRIVATE SFML_STATIC)

target_link_libraries(app ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})