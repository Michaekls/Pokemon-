cmake_minimum_required(VERSION 3.14)

project(Pokemon LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Pokemon
  main.cpp
  pokemon.cpp
  pokemon.h
  pokemon_ognisty.cpp
  pokemon_ognisty.h
  pokemon_wodny.cpp
  pokemon_wodny.h
  pokemon_roslinny.cpp
  pokemon_roslinny.h
  charmander.h
  charmander.cpp
  squirtle.cpp
  bulbasaur.cpp
  bulbasaur.h
  squirtle.h
  caterpie.cpp
  caterpie.h
  vulpix.cpp
  vulpix.h
  psyduck.cpp
  psyduck.h
  plecak.cpp
  plecak.h
)
target_link_libraries(Pokemon Qt${QT_VERSION_MAJOR}::Core)
