ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(ncplugin_SOURCES
  ncplugin.cpp)

SET(ncplugin_HEADERS
  ncplugin.h)

#SET(ncplugin_RESOURCES nc.qrc)

#SET(ncplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(ncplugin_HEADERS_MOC ${ncplugin_HEADERS})
#QT5_WRAP_UI(ncplugin_FORMS_HEADERS ${ncplugin_FORMS})
#QT5_ADD_RESOURCES(ncplugin_RESOURCES_RCC ${ncplugin_RESOURCES})

ADD_LIBRARY(ncplugin SHARED ${ncplugin_SOURCES} 
    ${ncplugin_HEADERS_MOC})
#    ${ncplugin_FORMS_HEADERS} 
#    ${ncplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(ncplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS ncplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
