
set(LIB_NAME "Smurf")
add_library(${LIB_NAME}
    STATIC
        src/Smurf.cpp
        src/SmurfImpl.cpp
        src/SmurfActions.cpp
        src/Crew.cpp
)
target_include_directories(${LIB_NAME}
    PUBLIC
        inc/smurf
    PRIVATE
        inc
)

set(EXE_NAME "Main_Program")
add_executable(${EXE_NAME}
    main.cpp
    src/App.cpp
)
target_link_libraries(${EXE_NAME}
    PRIVATE
        ${LIB_NAME}
        pthread
)
target_include_directories(${EXE_NAME}
    PRIVATE
        inc # for App.hpp
)