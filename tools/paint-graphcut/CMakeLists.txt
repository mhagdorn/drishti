SET(drishtipaint_SOURCES 
  drishtipaint.cpp 
  main.cpp 
  morphcurve.cpp
  bitmapthread.cpp 
  dcolordialog.cpp 
  dcolorwheel.cpp 
  imagewidget.cpp 
  global.cpp 
  gradienteditor.cpp 
  gradienteditorwidget.cpp 
  myslider.cpp 
  splineeditor.cpp 
  splineeditorwidget.cpp 
  splineinformation.cpp 
  splinetransferfunction.cpp 
  staticfunctions.cpp 
  transferfunctioncontainer.cpp 
  transferfunctioneditorwidget.cpp
  transferfunctionmanager.cpp 
  tagcoloreditor.cpp 
  coloreditor.cpp 
  curvegroup.cpp
  opacityeditor.cpp
  volume.cpp 
  volumefilemanager.cpp 
  volumemask.cpp
  graphcut/graph.cpp 
  graphcut/graphcut.cpp)

SET(drishtipaint_HEADERS 
  drishtipaint.h 
  bitmapthread.h 
  dcolordialog.h 
  dcolorwheel.h 
  imagewidget.h
  global.h 
  gradienteditor.h 
  gradienteditorwidget.h 
  myslider.h 
  morphcurve.h
  splineeditor.h 
  splineeditorwidget.h
  splineinformation.h 
  splinetransferfunction.h
  staticfunctions.h 
  transferfunctioncontainer.h 
  transferfunctioneditorwidget.h 
  transferfunctionmanager.h
  tagcoloreditor.h 
  coloreditor.h 
  curvegroup.h
  opacityeditor.h 
  volume.h 
  volumefilemanager.h 
  volumemask.h
  graphcut/graph.h 
  graphcut/graphcut.h
  graphcut/block.h 
  graphcut/point.h)

SET(drishtipaint_FORMS
  drishtipaint.ui)

SET(drishtipaint_RESOURCES paint.qrc)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/graphcut )
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/graphcut )

QT5_WRAP_CPP(drishtipaint_HEADERS_MOC ${drishtipaint_HEADERS})
QT5_WRAP_UI(drishtipaint_FORMS_HEADERS ${drishtipaint_FORMS})
QT5_ADD_RESOURCES(drishtipaint_RESOURCES_RCC ${drishtipaint_RESOURCES})

ADD_EXECUTABLE( drishtipaint 
    ${drishtipaint_SOURCES} 
    ${drishtipaint_HEADERS_MOC}
    ${drishtipaint_FORMS_HEADERS} 
    ${drishtipaint_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(drishtipaint 
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

qt5_use_modules(drishtipaint Widgets Xml)

INSTALL (TARGETS drishtipaint DESTINATION ${BIN_INSTALL_DIR})





