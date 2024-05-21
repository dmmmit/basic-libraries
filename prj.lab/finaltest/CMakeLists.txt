add_library(finaltest INTERFACE finaltest.hpp)
set_property(TARGET finaltest PROPERTY CXX_STANDARD 20)
target_include_directories(finaltest INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
