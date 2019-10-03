cmake_minimum_required(VERSION 3.2)

project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#project(print_ip VERSION 0.0.1)

configure_file(version.h.in version.h)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(print_ip main.cpp)
add_library(print_lib print.h)
add_library(checkmethods_lib checkmethods.h)
add_executable(test_print_ip test_print_ip.cpp)

set_target_properties(print_ip print_lib checkmethods_lib test_print_ip
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    LINKER_LANGUAGE CXX
)


#option(PACKAGE_TESTS "Build the tests" ON)
#if(PACKAGE_TESTS)
#    enable_testing()
#    add_subdirectory(googletest)
#endif()


target_link_libraries(print_ip PRIVATE
    print_lib checkmethods_lib 
)
target_link_libraries(test_print_ip PRIVATE
     print_lib checkmethods_lib gtest gmock gtest_main
)

if (MSVC)
    target_compile_options(print_ip PRIVATE
        /W4
    )
    target_compile_options(print_lib PRIVATE
        /W4
    )
    target_compile_options(checkmethods_lib PRIVATE
        /W4
    )
    target_compile_options(test_print_ip PRIVATE
       /W4
    )
else ()
    target_compile_options(print_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(print_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(checkmethods_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )	
    target_compile_options(test_print_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_print_ip test_print_ip)