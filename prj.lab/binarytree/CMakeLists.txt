add_library(binarytree binarytree.cpp binarytree.hpp)
set_property(TARGET binarytree PROPERTY CXX_STANDARD 20)
target_include_directories(binarytree PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS binarytree)
