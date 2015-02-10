ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(dicomplugin_SOURCES
  dicomplugin.cpp)

SET(dicomplugin_HEADERS
  dicomplugin.h)

#SET(dicomplugin_RESOURCES dicom.qrc)

#SET(dicomplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(dicomplugin_HEADERS_MOC ${dicomplugin_HEADERS})
#QT5_WRAP_UI(dicomplugin_FORMS_HEADERS ${dicomplugin_FORMS})
#QT5_ADD_RESOURCES(dicomplugin_RESOURCES_RCC ${dicomplugin_RESOURCES})

ADD_LIBRARY(dicomplugin SHARED ${dicomplugin_SOURCES} 
    ${dicomplugin_HEADERS_MOC})
#    ${dicomplugin_FORMS_HEADERS} 
#    ${dicomplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(dicomplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX} ${ITK_LIBRARIES})

INSTALL (TARGETS dicomplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
