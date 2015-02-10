ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(smoothingplugin_SOURCES 
  smoothing.cpp 
  filter.cpp)

SET(smoothingplugin_HEADERS
  smoothing.h 
  filter.h )

SET(smoothingplugin_FORMS ../../../propertyeditor.ui)


QT5_WRAP_CPP(smoothingplugin_HEADERS_MOC ${smoothingplugin_HEADERS})
QT5_WRAP_UI(smoothingplugin_FORMS_HEADERS ${smoothingplugin_FORMS})

ADD_LIBRARY(smoothingplugin SHARED ${smoothingplugin_SOURCES}
    ${smoothingplugin_HEADERS_MOC}
    ${smoothinggplugin_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(smoothingplugin 
  common ${ITK_LIBRARIES}
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS smoothingplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins/ITK)
