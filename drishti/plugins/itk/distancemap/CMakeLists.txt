ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(distancemapplugin_SOURCES 
  distancemap.cpp 
  filter.cpp)

SET(distancemapplugin_HEADERS
  distancemap.h 
  filter.h )

SET(distancemapplugin_FORMS ../../../propertyeditor.ui)


QT5_WRAP_CPP(distancemapplugin_HEADERS_MOC ${distancemapplugin_HEADERS})
QT5_WRAP_UI(distancemapplugin_FORMS_HEADERS ${distancemapplugin_FORMS})

ADD_LIBRARY(distancemapplugin SHARED ${distancemapplugin_SOURCES}
    ${distancemapplugin_HEADERS_MOC}
    ${distancemapgplugin_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(distancemapplugin 
  common ${ITK_LIBRARIES}
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS distancemapplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins/ITK)
