ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(tomplugin_SOURCES
  tomplugin.cpp)

SET(tomplugin_HEADERS
  tomplugin.h tomhead.h)

#SET(tomplugin_RESOURCES tom.qrc)

#SET(tomplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(tomplugin_HEADERS_MOC ${tomplugin_HEADERS})
#QT5_WRAP_UI(tomplugin_FORMS_HEADERS ${tomplugin_FORMS})
#QT5_ADD_RESOURCES(tomplugin_RESOURCES_RCC ${tomplugin_RESOURCES})

ADD_LIBRARY(tomplugin SHARED ${tomplugin_SOURCES} 
    ${tomplugin_HEADERS_MOC})
#    ${tomplugin_FORMS_HEADERS} 
#    ${tomplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(tomplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS tomplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
