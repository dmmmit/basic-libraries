add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational)

add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr StackArr)

add_executable(test_stacklst test_stacklst.cpp)
target_link_libraries(test_stacklst StackLstT)

add_executable(test_dequeue test_dequeue.cpp)
target_link_libraries(test_dequeue Dequeue)

add_executable(test_hashtable test_hashtable.cpp)
target_link_libraries(test_hashtable hashtable)
#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stackarr)

add_executable(test_binarytree test_binarytree.cpp)
target_link_libraries(test_binarytree binarytree)

add_executable(test_finaltest test_finaltest.cpp)
target_link_libraries(test_finaltest finaltest)