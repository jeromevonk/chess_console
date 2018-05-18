#==============================================================================
#    _____ _    _ ______  _____ _____
#   / ____| |  | |  ____|/ ____/ ____|
#  | |    | |__| | |__  | (___| (___ 
#  | |    |  __  |  __|  \___ \\___ \
#  | |____| |  | | |____ ____) |___) |
#   \_____|_|  |_|______|_____/_____/
#
#  /source/CMakeLists.txt
#
#==============================================================================

cmake_minimum_required (VERSION 2.6)

project (chess CXX)

add_executable(chess chess.cpp user_interface.cpp main.cpp)

set_property(TARGET chess PROPERTY CXX_STANDARD 11)
set_property(TARGET chess PROPERTY CXX_STANDARD_REQUIRED ON) 
