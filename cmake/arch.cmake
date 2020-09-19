function(target_arch_compile_options target)
    if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
        target_compile_options(${target} PUBLIC "/Zc:__cplusplus")
        target_compile_options(${target} PRIVATE "/wd4250")
    endif()
endfunction()

include(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/CMakeCxxModules/CXXModules.cmake)
