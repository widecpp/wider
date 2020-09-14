if(ATKMM_INCLUDE_DIR)
    # Already in cache, be silent
    set(ATKMM_FIND_QUIETLY TRUE)
endif(ATKMM_INCLUDE_DIR)

find_path(ATKMM_INCLUDE_DIR atkmm/action.h)
find_library(ATKMM_LIBRARY
	NAMES atkmm libatkmm)
# Handle the QUIETLY and REQUIRED arguments and set ATKMM_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(atkmm DEFAULT_MSG
	ATKMM_INCLUDE_DIR
	ATKMM_LIBRARY)

if(ATKMM_FOUND)
  set(ATKMM_LIBRARIES ${ATKMM_LIBRARY})
else(ATKMM_FOUND)
  set(ATKMM_LIBRARIES)
endif(ATKMM_FOUND)

mark_as_advanced(ATKMM_INCLUDE_DIR)
mark_as_advanced(ATKMM_LIBRARY)