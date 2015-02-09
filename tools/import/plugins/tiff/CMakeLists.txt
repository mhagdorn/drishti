ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

FIND_PACKAGE(TIFF)

if (TIFF_FOUND)

SET(tiffplugin_SOURCES
  tiffplugin.cpp)

SET(tiffplugin_HEADERS
  tiffplugin.h)

#SET(tiffplugin_RESOURCES tiff.qrc)

#SET(tiffplugin_FORMS ../../propertyeditor.ui)

QT4_WRAP_CPP(tiffplugin_HEADERS_MOC ${tiffplugin_HEADERS})
#QT4_WRAP_UI(tiffplugin_FORMS_HEADERS ${tiffplugin_FORMS})
#QT4_ADD_RESOURCES(tiffplugin_RESOURCES_RCC ${tiffplugin_RESOURCES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(${TIFF_INCLUDE_DIRS})

ADD_LIBRARY(tiffplugin SHARED ${tiffplugin_SOURCES} 
    ${tiffplugin_HEADERS_MOC})
#    ${tiffplugin_FORMS_HEADERS} 
#    ${tiffplugin_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(tiffplugin common
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX} ${TIFF_LIBRARIES})

INSTALL (TARGETS tiffplugin DESTINATION ${PLUGIN_INSTALL_DIR}/importplugins)

else()
MESSAGE( WARNING "Could not find tiff library, disabling hdf4 plugin")

endif (TIFF_FOUND)
