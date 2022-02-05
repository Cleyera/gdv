include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(path IN LISTS sources)
    get_filename_component(target ${path} NAME_WE)
    add_executable(${target} ${path})
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endforeach()
