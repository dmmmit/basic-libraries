add_library(Dequeue dequeue.cpp dequeue.hpp)
set_property(TARGET Dequeue PROPERTY CXX_STANDARD 20)
target_include_directories(Dequeue PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS Dequeue)