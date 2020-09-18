if(CAIRO_INCLUDE_DIR)
    # Already in cache, be silent
    set(CAIRO_FIND_QUIETLY TRUE)
endif(CAIRO_INCLUDE_DIR)

find_path(CAIRO_INCLUDE_DIR cairo/cairo.h)

find_library(CAIRO_LIBRARY_RELEASE NAMES cairo libcairo)
find_library(CAIRO_LIBRARY_DEBUG NAMES cairod libcairod)

# И так, я понял как работает это говно.
# Оно (выражения генератора) будет работать не на этапе `cmake найди мне говно`, а на этапе прямо перед сборкой
# В результате строку мы имеет вот именно такого дерьмового вида,
# А компилятору пойдет строка в зависимости от выбранного режима
set(CAIRO_LIBRARY "$<IF:$<CONFIG:Debug>,${CAIRO_LIBRARY_DEBUG},${CAIRO_LIBRARY_RELEASE}>")

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