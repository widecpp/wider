if(GLIB_INCLUDE_DIR)
    # Already in cache, be silent
    set(GLIB_FIND_QUIETLY TRUE)
endif(GLIB_INCLUDE_DIR)

find_path(GLIB_INCLUDE_DIR glib/glib-init.h)
find_library(GLIB_LIBRARY
    NAMES glib libglib glib-2.0 libglib-2.0)
# Handle the QUIETLY and REQUIRED arguments and set GLIB_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(glib DEFAULT_MSG
    GLIB_INCLUDE_DIR
    GLIB_LIBRARY)

if(GLIB_FOUND)
  set(GLIB_LIBRARIES ${GLIB_LIBRARY})
else(GLIB_FOUND)
  set(GLIB_LIBRARIES)
endif(GLIB_FOUND)