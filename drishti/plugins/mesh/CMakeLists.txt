ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(meshplugin_SOURCES 
  meshplugin.cpp 
  meshgenerator.cpp 
  marchingcubes.cpp 
  ply.c)

SET(meshplugin_HEADERS
  meshplugin.h
  meshgenerator.h
  marchingcubes.h
  ply.h
  lookuptable.h )

SET(meshplugin_RESOURCES mesh.qrc)

SET(meshplugin_FORMS ../../propertyeditor.ui)


QT4_WRAP_CPP(meshplugin_HEADERS_MOC ${meshplugin_HEADERS})
QT4_WRAP_UI(meshplugin_FORMS_HEADERS ${meshplugin_FORMS})
QT4_ADD_RESOURCES(meshplugin_RESOURCES_RCC ${meshplugin_RESOURCES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_LIBRARY(meshplugin SHARED ${meshplugin_SOURCES} 
    ${meshplugin_HEADERS_MOC}
    ${meshplugin_FORMS_HEADERS} 
    ${meshplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(meshplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS meshplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins)
