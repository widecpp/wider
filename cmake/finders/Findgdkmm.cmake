if(GDKMM_INCLUDE_DIR)
    # Already in cache, be silent
    set(GDKMM_FIND_QUIETLY TRUE)
endif(GDKMM_INCLUDE_DIR)

find_package(glib)
find_package(sigc)
if(GLIB_FOUND)
	find_path(GDKMM_INCLUDE_DIR gdkmm/general.h)
	find_library(GDKMM_LIBRARY
	    NAMES gdkmm libgdkmm)
	# Handle the QUIETLY and REQUIRED arguments and set GDKMM_FOUND
	# to TRUE if all listed variables are TRUE.
	include(FindPackageHandleStandardArgs)
	find_package_handle_standard_args(gdkmm DEFAULT_MSG
	    GDKMM_INCLUDE_DIR
	    GDKMM_LIBRARY)
endif(GLIB_FOUND)

if(GDKMM_FOUND)
  set(GDKMM_LIBRARIES ${GDKMM_LIBRARY} ${GLIB_LIBRARIES} ${SIGC_LIBRARIES})
else(GDKMM_FOUND)
  set(GDKMM_LIBRARIES)
endif(GDKMM_FOUND)

mark_as_advanced(GDKMM_INCLUDE_DIR)
mark_as_advanced(GDKMM_LIBRARY)