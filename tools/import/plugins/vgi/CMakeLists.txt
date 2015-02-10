ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(vgiplugin_SOURCES
  vgiplugin.cpp)

SET(vgiplugin_HEADERS
  vgiplugin.h)

#SET(vgiplugin_RESOURCES vgi.qrc)

#SET(vgiplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(vgiplugin_HEADERS_MOC ${vgiplugin_HEADERS})
#QT5_WRAP_UI(vgiplugin_FORMS_HEADERS ${vgiplugin_FORMS})
#QT5_ADD_RESOURCES(vgiplugin_RESOURCES_RCC ${vgiplugin_RESOURCES})

ADD_LIBRARY(vgiplugin SHARED ${vgiplugin_SOURCES} 
    ${vgiplugin_HEADERS_MOC})
#    ${vgiplugin_FORMS_HEADERS} 
#    ${vgiplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(vgiplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS vgiplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
