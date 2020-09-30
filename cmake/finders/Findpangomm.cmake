if(PANGOMM_INCLUDE_DIR)
    # Already in cache, be silent
    set(PANGOMM_FIND_QUIETLY TRUE)
endif(PANGOMM_INCLUDE_DIR)

find_path(PANGOMM_INCLUDE_DIR pangomm.h)
find_library(PANGOMM_LIBRARY
	NAMES pangomm libpangomm)
# Handle the QUIETLY and REQUIRED arguments and set PANGOMM_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(pangomm DEFAULT_MSG
	PANGOMM_INCLUDE_DIR
	PANGOMM_LIBRARY)

if(PANGOMM_FOUND)
  set(PANGOMM_LIBRARIES ${PANGOMM_LIBRARY})
else(PANGOMM_FOUND)
  set(PANGOMM_LIBRARIES)
endif(PANGOMM_FOUND)

mark_as_advanced(PANGOMM_INCLUDE_DIR)
mark_as_advanced(PANGOMM_LIBRARY)