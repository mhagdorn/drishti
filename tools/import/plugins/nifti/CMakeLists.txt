ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(niftiplugin_SOURCES
  niftiplugin.cpp)

SET(niftiplugin_HEADERS
  niftiplugin.h)

#SET(niftiplugin_RESOURCES nifti.qrc)

#SET(niftiplugin_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(niftiplugin_HEADERS_MOC ${niftiplugin_HEADERS})
#QT5_WRAP_UI(niftiplugin_FORMS_HEADERS ${niftiplugin_FORMS})
#QT5_ADD_RESOURCES(niftiplugin_RESOURCES_RCC ${niftiplugin_RESOURCES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_LIBRARY(niftiplugin SHARED ${niftiplugin_SOURCES} 
    ${niftiplugin_HEADERS_MOC})
#    ${niftiplugin_FORMS_HEADERS} 
#    ${niftiplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(niftiplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX} ${ITK_LIBRARIES})

INSTALL (TARGETS niftiplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
