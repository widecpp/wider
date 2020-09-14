if(GTKMM_INCLUDE_DIR)
    # Already in cache, be silent
    set(GTKMM_FIND_QUIETLY TRUE)
endif(GTKMM_INCLUDE_DIR)

find_package(atkmm)
find_package(gdkmm)
find_package(cairomm)
find_package(glib)
find_package(sigc)
if(GLIB_FOUND)
	find_path(GTKMM_INCLUDE_DIR gtkmm/application.h)
	find_library(GTKMM_LIBRARY
	    NAMES gtkmm libgtkmm)
	# Handle the QUIETLY and REQUIRED arguments and set GTKMM_FOUND
	# to TRUE if all listed variables are TRUE.
	include(FindPackageHandleStandardArgs)
	find_package_handle_standard_args(gtkmm DEFAULT_MSG
	    GTKMM_INCLUDE_DIR
	    GTKMM_LIBRARY)
endif(GLIB_FOUND)

if(GTKMM_FOUND)
  set(GTKMM_LIBRARIES ${GTKMM_LIBRARY} ${GDKMM_LIBRARIES} ${ATKMM_LIBRARIES} ${CAIROMM_LIBRARIES} ${GLIB_LIBRARIES} ${SIGC_LIBRARIES})
else(GTKMM_FOUND)
  set(GTKMM_LIBRARIES)
endif(GTKMM_FOUND)

mark_as_advanced(GTKMM_INCLUDE_DIR)
mark_as_advanced(GTKMM_LIBRARY)