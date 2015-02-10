ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(imagestackplugin_SOURCES
  imagestackplugin.cpp
  volumefilemanager.cpp)

SET(imagestackplugin_HEADERS
  imagestackplugin.h
  volumefilemanager.h)

#SET(imagestackplugin_RESOURCES imagestack.qrc)

#SET(imagestackplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(imagestackplugin_HEADERS_MOC ${imagestackplugin_HEADERS})
#QT5_WRAP_UI(imagestackplugin_FORMS_HEADERS ${imagestackplugin_FORMS})
#QT5_ADD_RESOURCES(imagestackplugin_RESOURCES_RCC ${imagestackplugin_RESOURCES})

ADD_LIBRARY(imagestackplugin SHARED ${imagestackplugin_SOURCES} 
    ${imagestackplugin_HEADERS_MOC})
#    ${imagestackplugin_FORMS_HEADERS} 
#    ${imagestackplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(imagestackplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS imagestackplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
