cmake_minimum_required(VERSION 3.5)
project(cvec234_examples)

file(GLOB cvec234 "../carma/*.c")

add_executable(tests tests.c ${cvec234})
target_compile_features(tests PRIVATE c_std_23)
target_include_directories(tests PRIVATE ..)

# Add warning flags for GCC
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(WARN_FLAGS
            -Wall           # Enable all standard warnings
            -Wextra         # Enable extra warnings
            -Wpedantic      # Enable strict ISO C and ISO C++ warnings
            -Wshadow        # Warn if a variable declaration shadows one from a parent context
            -Wpointer-arith # Warn about anything that depends on the "size of" a function type or of void
            -Wcast-qual     # Warn whenever a pointer is cast so as to remove a type qualifier from the target type
            -Wstrict-overflow=5 # Detect cases where the compiler optimizes based on the assumption that signed overflow does not occur
            -Wstrict-aliasing=2 # Warn about code which might break the strict aliasing rules
            -Wundef         # Warn if an undefined identifier is evaluated in an #if directive
            -Wcast-align    # Warn whenever a pointer is cast such that the required alignment of the target is increased
    )

    target_compile_options(tests PRIVATE ${WARN_FLAGS})
endif()
