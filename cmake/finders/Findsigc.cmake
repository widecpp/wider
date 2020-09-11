if(SIGC_INCLUDE_DIR)
    # Already in cache, be silent
    set(SIGC_FIND_QUIETLY TRUE)
endif(SIGC_INCLUDE_DIR)

find_path(SIGC_INCLUDE_DIR sigc++/sigc++.h)
find_library(SIGC_LIBRARY
    NAMES sigc libsigc sigc-2.0 libsigc-2.0)
# Handle the QUIETLY and REQUIRED arguments and set SIGC_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(sigc DEFAULT_MSG
    SIGC_INCLUDE_DIR
    SIGC_LIBRARY)

if(SIGC_FOUND)
  set(SIGC_LIBRARIES ${SIGC_LIBRARY})
else(SIGC_FOUND)
  set(SIGC_LIBRARIES)
endif(SIGC_FOUND)