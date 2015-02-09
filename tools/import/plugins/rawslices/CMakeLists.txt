ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(rawslicesplugin_SOURCES
  rawslicesplugin.cpp
  loadrawdialog.cpp)

SET(rawslicesplugin_HEADERS
  rawslicesplugin.h
  loadrawdialog.h)

#SET(rawplugin_RESOURCES raw.qrc)

SET(rawslicesplugin_FORMS loadrawdialog.ui)

QT4_WRAP_CPP(rawslicesplugin_HEADERS_MOC ${rawslicesplugin_HEADERS})
QT4_WRAP_UI(rawslicesplugin_FORMS_HEADERS ${rawslicesplugin_FORMS})
#QT4_ADD_RESOURCES(rawslicesplugin_RESOURCES_RCC ${rawslicesplugin_RESOURCES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )

ADD_LIBRARY(rawslicesplugin SHARED ${rawslicesplugin_SOURCES} 
    ${rawslicesplugin_HEADERS_MOC}
    ${rawslicesplugin_FORMS_HEADERS})
#    ${rawslicesplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(rawslicesplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS rawslicesplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)
