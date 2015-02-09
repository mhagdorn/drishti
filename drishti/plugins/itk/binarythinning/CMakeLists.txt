ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET(binarythinningplugin_SOURCES 
  binarythinning.cpp 
  skeletonizer.cpp)

SET(binarythinningplugin_HEADERS
  binarythinning.h 
  itkBinaryThinningImageFilter3D.h 
  skeletonizer.h )

SET(binarythinningplugin_FORMS ../../../propertyeditor.ui)


QT4_WRAP_CPP(binarythinningplugin_HEADERS_MOC ${binarythinningplugin_HEADERS})
QT4_WRAP_UI(binarythinningplugin_FORMS_HEADERS ${binarythinningplugin_FORMS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_LIBRARY(binarythinningplugin SHARED ${binarythinningplugin_SOURCES}
    ${binarythinningplugin_HEADERS_MOC}
    ${binarythinningplugin_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(binarythinningplugin 
  common ${ITK_LIBRARIES}
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INSTALL (TARGETS binarythinningplugin DESTINATION ${PLUGIN_INSTALL_DIR}/renderplugins/ITK)
