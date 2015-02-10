ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(grdplugin_SOURCES
  grdplugin.cpp
  loadrawdialog.cpp)

SET(grdplugin_HEADERS
  grdplugin.h
  loadrawdialog.h)

#SET(grdplugin_RESOURCES grd.qrc)

SET(grdplugin_FORMS loadrawdialog.ui)

QT5_WRAP_CPP(grdplugin_HEADERS_MOC ${grdplugin_HEADERS})
QT5_WRAP_UI(grdplugin_FORMS_HEADERS ${grdplugin_FORMS})
#QT5_ADD_RESOURCES(grdplugin_RESOURCES_RCC ${grdplugin_RESOURCES})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )

ADD_LIBRARY(grdplugin SHARED ${grdplugin_SOURCES} 
    ${grdplugin_HEADERS_MOC}
    ${grdplugin_FORMS_HEADERS})
#    ${grdplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(grdplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS grdplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
