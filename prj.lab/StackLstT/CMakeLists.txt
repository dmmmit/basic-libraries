add_library(StackLstT StackLstT.cpp StackLstT.hpp)
set_property(TARGET StackLstT PROPERTY CXX_STANDARD 20)
target_include_directories(StackLstT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS StackLstT)
