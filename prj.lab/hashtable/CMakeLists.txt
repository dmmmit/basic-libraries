add_library(hashtable INTERFACE hashtable.hpp)
set_property(TARGET hashtable PROPERTY CXX_STANDARD 20)
target_include_directories(hashtable INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
