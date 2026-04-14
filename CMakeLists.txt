cmake_minimum_required(VERSION 3.15)
project(Chess LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. DOWNLOAD GLFW ---
include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.8
)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0.9.9.8 # Or a more recent version
)

FetchContent_MakeAvailable(glfw glm)

find_package(OpenGL REQUIRED)

add_executable(ChessGame 
    main.cpp 
    Game/Game.cpp
    Board/Board.cpp
    Tile/Tile.cpp
    Piece/Piece.cpp
    Texture/Texture.cpp
    stb_image.cpp
    Dependencies/glad/src/glad.c
)

target_include_directories(ChessGame PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}             
    ${CMAKE_CURRENT_SOURCE_DIR}/Game             
    ${CMAKE_CURRENT_SOURCE_DIR}/Board
    ${CMAKE_CURRENT_SOURCE_DIR}/Tile
    ${CMAKE_CURRENT_SOURCE_DIR}/Piece
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture
    ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/glad/include
)
target_link_libraries(ChessGame PRIVATE glfw OpenGL::GL glm::glm)