SET(drishtipaint_SOURCES 
  drishtipaint.cpp 
  main.cpp 
  morphcurve.cpp
  bitmapthread.cpp 
  dcolordialog.cpp 
  dcolorwheel.cpp 
  fiber.cpp 
  fibergroup.cpp
  imagewidget.cpp 
  global.cpp 
  gradienteditor.cpp 
  gradienteditorwidget.cpp 
  livewire.cpp 
  myslider.cpp 
  morphcurve.cpp 
  morphslice.cpp 
  propertyeditor.cpp
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
  viewer.cpp
  volume.cpp 
  volumefilemanager.cpp 
  volumemask.cpp
  graphcut/graph.cpp 
  graphcut/graphcut.cpp
  ply.c 
  marchingcubes.cpp 
  showhelp.cpp 
  getmemorysize.cpp 
  popupslider.cpp)

SET(drishtipaint_HEADERS 
  drishtipaint.h 
  bitmapthread.h 
  dcolordialog.h 
  dcolorwheel.h 
  fiber.h 
  fibergroup.h
  imagewidget.h
  global.h 
  gradienteditor.h 
  gradienteditorwidget.h 
  livewire.h 
  myslider.h 
  morphcurve.h
  morphslice.h 
  propertyeditor.h
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
  viewer.h 
  volume.h 
  volumefilemanager.h 
  volumemask.h
  graphcut/graph.h 
  graphcut/graphcut.h
  graphcut/block.h 
  graphcut/point.h
  ply.h 
  lookuptable.h 
  marchingcubes.h 
  showhelp.h
  getmemorysize.h 
  popupslider.h)

SET(drishtipaint_FORMS
  drishtipaint.ui
  viewermenu.ui
  graphcutmenu.ui
  curvesmenu.ui
  fibersmenu.ui
  propertyeditor.ui)

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

qt5_use_modules(drishtipaint Widgets Xml OpenGL)

INSTALL (TARGETS drishtipaint DESTINATION ${BIN_INSTALL_DIR})





