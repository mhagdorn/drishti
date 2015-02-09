ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(metaimageplugin_SOURCES
  metaimageplugin.cpp)

SET(metaimageplugin_HEADERS
  metaimageplugin.h)

#SET(metaimageplugin_RESOURCES metaimage.qrc)

#SET(metaimageplugin_FORMS ../../propertyeditor.ui)

QT4_WRAP_CPP(metaimageplugin_HEADERS_MOC ${metaimageplugin_HEADERS})
#QT4_WRAP_UI(metaimageplugin_FORMS_HEADERS ${metaimageplugin_FORMS})
#QT4_ADD_RESOURCES(metaimageplugin_RESOURCES_RCC ${metaimageplugin_RESOURCES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_LIBRARY(metaimageplugin SHARED ${metaimageplugin_SOURCES} 
    ${metaimageplugin_HEADERS_MOC})
#    ${metaimageplugin_FORMS_HEADERS} 
#    ${metaimageplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(metaimageplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX} ${ITK_LIBRARIES})

INSTALL (TARGETS metaimageplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
