ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(meshpaintplugin_SOURCES 
  meshgenerator.cpp
  meshplugin.cpp
  ply.c)

SET(meshpaintplugin_HEADERS
  lookuptable.h
  meshgenerator.h
  meshplugin.h
  ply.h )

SET(meshpaintplugin_RESOURCES meshpaint.qrc)

SET(meshpaintplugin_FORMS ../../propertyeditor.ui)


QT5_WRAP_CPP(meshpaintplugin_HEADERS_MOC ${meshpaintplugin_HEADERS})
QT5_WRAP_UI(meshpaintplugin_FORMS_HEADERS ${meshpaintplugin_FORMS})
QT5_ADD_RESOURCES(meshpaintplugin_RESOURCES_RCC ${meshpaintplugin_RESOURCES})

ADD_LIBRARY(meshpaintplugin SHARED ${meshpaintplugin_SOURCES} 
    ${meshpaintplugin_HEADERS_MOC}
    ${meshpaintplugin_FORMS_HEADERS} 
    ${meshpaintplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(meshpaintplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS meshpaintplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins)
