add_executable(app main.cpp headers.h game.h game.cpp screens.h screens.cpp levels.h levels.cpp
maps.h maps.cpp collision.cpp player.h player.cpp enemies.h enemies.cpp)

target_include_directories(app PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app PUBLIC cxx_std_17)
target_compile_definitions(app PRIVATE SFML_STATIC)

target_link_libraries(app ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})