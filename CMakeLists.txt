cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
project(lightning-test-main)

include(FetchContent)
FetchContent_Declare(pennylane_lightning
                     GIT_REPOSITORY https://github.com/PennyLaneAI/pennylane-lightning.git
                     GIT_TAG        master
)
FetchContent_MakeAvailable(pennylane_lightning)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE lightning_gates lightning_simulator lightning_utils)
