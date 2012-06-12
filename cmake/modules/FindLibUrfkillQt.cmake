# Find liburfkill-qt includes and library
#
# This module defines
#  LibUrfkillQt_INCLUDE_DIR
#  LibUrfkillQt_LIBRARIES, the libraries to link against to use LibUrfkillQt.
#  LibUrfkillQt_FOUND, If false, do not try to use LibUrfkillQt
#

IF (LibUrfkillQt_LIBRARIES AND LibUrfkillQt_INCLUDE_DIR)
    SET(LibUrfkillQt_FIND_QUIETLY TRUE) # Already in cache, be silent
ENDIF (LibUrfkillQt_LIBRARIES AND LibUrfkillQt_INCLUDE_DIR)

MESSAGE(STATUS "Looking for liburfkill-qt")
find_path(LibUrfkillQt_INCLUDE_DIR liburfkill-qt/urfkill.h)
find_library(LibUrfkillQt_LIBRARIES liburfkill-qt)

MARK_AS_ADVANCED(LibUrfkillQt_INCLUDE_DIR)
MARK_AS_ADVANCED(LibUrfkillQt_LIBRARIES)

IF (LibUrfkillQt_INCLUDE_DIR AND LibUrfkillQt_LIBRARIES)
    SET(LibUrfkillQt_FOUND TRUE)
ENDIF (LibUrfkillQt_INCLUDE_DIR AND LibUrfkillQt_LIBRARIES)

IF (LibUrfkillQt_FOUND)
   IF (NOT LibUrfkillQt_FIND_QUIETLY)
        MESSAGE(STATUS "Found liburfkill-qt")
        MESSAGE(STATUS "  libraries : ${LibUrfkillQt_LIBRARIES}")
        MESSAGE(STATUS "  includes  : ${LibUrfkillQt_INCLUDE_DIR}")
   ENDIF (NOT LibUrfkillQt_FIND_QUIETLY)
ELSE (LibUrfkillQt_FOUND)
    IF (LibUrfkillQt_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find liburfkill-qt")
    ENDIF (LibUrfkillQt_FIND_REQUIRED)
ENDIF (LibUrfkillQt_FOUND)
