if(CAIRO_INCLUDE_DIR)
    # Already in cache, be silent
    set(CAIRO_FIND_QUIETLY TRUE)
endif(CAIRO_INCLUDE_DIR)

find_path(CAIRO_INCLUDE_DIR cairo/cairo.h)

if ($<CONFIG:Debug>)
  find_library(CAIRO_LIBRARY NAMES cairod libcairod)
else()
  find_library(CAIRO_LIBRARY NAMES cairo libcairo)
endif()
# Handle the QUIETLY and REQUIRED arguments and set CAIRO_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(cairo DEFAULT_MSG
	CAIRO_INCLUDE_DIR
	CAIRO_LIBRARY)

if(CAIRO_FOUND)
  set(CAIRO_LIBRARIES ${CAIRO_LIBRARY})
else(CAIRO_FOUND)
  set(CAIRO_LIBRARIES)
endif(CAIRO_FOUND)

mark_as_advanced(CAIRO_INCLUDE_DIR)
mark_as_advanced(CAIRO_LIBRARY)