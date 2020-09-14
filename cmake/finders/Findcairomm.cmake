if(CAIROMM_INCLUDE_DIR)
    # Already in cache, be silent
    set(CAIROMM_FIND_QUIETLY TRUE)
endif(CAIROMM_INCLUDE_DIR)

find_package(cairo)
if(CAIRO_FOUND)
  find_path(CAIROMM_INCLUDE_DIR cairomm/cairomm.h)
  find_library(CAIROMM_LIBRARY
    NAMES cairomm libcairomm cairomm-1.0 libcairomm-1.0)
  # Handle the QUIETLY and REQUIRED arguments and set CAIROMM_FOUND
  # to TRUE if all listed variables are TRUE.
  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(cairomm DEFAULT_MSG
    CAIROMM_INCLUDE_DIR
    CAIROMM_LIBRARY)
endif(CAIRO_FOUND)

if(CAIROMM_FOUND)
  set(CAIROMM_LIBRARIES ${CAIROMM_LIBRARY} ${CAIRO_LIBRARIES})
else(CAIROMM_FOUND)
  set(CAIROMM_LIBRARIES)
endif(CAIROMM_FOUND)

mark_as_advanced(CAIROMM_INCLUDE_DIR)
mark_as_advanced(CAIROMM_LIBRARY)