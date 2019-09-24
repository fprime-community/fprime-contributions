#
#   Copyright 2004-2016, by the California Institute of Technology.
#   ALL RIGHTS RESERVED. United States Government Sponsorship
#   acknowledged. Any commercial use must be negotiated with the Office
#   of Technology Transfer at the California Institute of Technology.
#
#   This software may be subject to U.S. export control laws and
#   regulations.  By accepting this document, the user agrees to comply
#   with all U.S. export laws and regulations.  User has the
#   responsibility to obtain export licenses, or other export authority
#   as may be required before exporting such information to foreign
#   countries or providing access to foreign persons.
#

macro(genmodmk)

# TODO(mereweth) - support simultaneous builds with multiple targets
FILE(
    WRITE ${CMAKE_BINARY_DIR}/modmk.cmake
"
string (REPLACE \";\" \" -I \" incs \"${catkin_INCLUDE_DIRS}\")
string (REPLACE \";\" \" \" libs \"${catkin_LIBRARIES}\")

FILE(APPEND \${MODMK} \"EXTRA_INC_DIRS = -I \")
FILE(APPEND \${MODMK} \${incs})

FILE(APPEND \${MODMK} \"\\nEXTRA_LIBS = \")
FILE(APPEND \${MODMK} \${libs})
FILE(APPEND \${MODMK} \"\\n\")
"
)

ADD_CUSTOM_COMMAND(
  OUTPUT NotAFile
  COMMAND ${CMAKE_COMMAND} ARGS -E echo "Forcing generation of mod.mk for ${PROJECT_NAME}"
)

ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/mod.mk
    COMMAND ${CMAKE_COMMAND}
            -DMODMK=${CMAKE_CURRENT_SOURCE_DIR}/mod.mk
            -P ${CMAKE_BINARY_DIR}/modmk.cmake
    DEPENDS  NotAFile #${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
ADD_CUSTOM_TARGET(modmk ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mod.mk)

endmacro(genmodmk)
