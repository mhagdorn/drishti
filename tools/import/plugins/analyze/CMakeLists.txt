ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(analyzeplugin_SOURCES
  analyzeplugin.cpp)

SET(analyzeplugin_HEADERS
  analyzeplugin.h)

#SET(analyzeplugin_RESOURCES analyze.qrc)

#SET(analyzeplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(analyzeplugin_HEADERS_MOC ${analyzeplugin_HEADERS})
#QT5_WRAP_UI(analyzeplugin_FORMS_HEADERS ${analyzeplugin_FORMS})
#QT5_ADD_RESOURCES(analyzeplugin_RESOURCES_RCC ${analyzeplugin_RESOURCES})

ADD_LIBRARY(analyzeplugin SHARED ${analyzeplugin_SOURCES} 
    ${analyzeplugin_HEADERS_MOC})
#    ${analyzeplugin_FORMS_HEADERS} 
#    ${analyzeplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(analyzeplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS analyzeplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
