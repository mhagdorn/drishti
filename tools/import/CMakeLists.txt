SET(drishtiimport_SOURCES 
  global.cpp 
  staticfunctions.cpp 
  fileslistdialog.cpp 
  main.cpp 
  remapwidget.cpp 
  remaphistogramline.cpp 
  remaphistogramwidget.cpp 
  remapimage.cpp 
  gradienteditor.cpp 
  gradienteditorwidget.cpp 
  dcolordialog.cpp 
  dcolorwheel.cpp 
  drishtiimport.cpp 
  myslider.cpp 
  raw2pvl.cpp 
  savepvldialog.cpp 
  volumedata.cpp
  volumefilemanager.cpp) 

SET(drishtiimport_HEADERS 
  global.h 
  common.h 
  commonqtclasses.h
  staticfunctions.h 
  fileslistdialog.h 
  remapwidget.h 
  remaphistogramline.h 
  remaphistogramwidget.h 
  remapimage.h 
  gradienteditor.h 
  gradienteditorwidget.h 
  dcolordialog.h 
  dcolorwheel.h 
  drishtiimport.h 
  myslider.h 
  raw2pvl.h 
  savepvldialog.h 
  volumefilemanager.h 
  volumedata.h 
  volinterface.h 
  lookuptable.h)

SET(drishtiimport_FORMS
  remapwidget.ui 
  savepvldialog.ui 
  drishtiimport.ui 
  fileslistdialog.ui )

SET(drishtiimport_RESOURCES import.qrc)

QT5_WRAP_CPP(drishtiimport_HEADERS_MOC ${drishtiimport_HEADERS})
QT5_WRAP_UI(drishtiimport_FORMS_HEADERS ${drishtiimport_FORMS})
QT5_ADD_RESOURCES(drishtiimport_RESOURCES_RCC ${drishtiimport_RESOURCES})

ADD_EXECUTABLE( drishtiimport 
    ${drishtiimport_SOURCES} 
    ${drishtiimport_HEADERS_MOC}
    ${drishtiimport_FORMS_HEADERS} 
    ${drishtiimport_RESOURCES_RCC})
TARGET_LINK_LIBRARIES(drishtiimport 
   ${QT_LIBRARIES} ${QGLVIEWER_LIBRARIES}
   ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}
   ${NETCDF_LIBRARIES_CXX})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )

qt5_use_modules(drishtiimport Widgets Xml)

ADD_SUBDIRECTORY(plugins)

INSTALL (TARGETS drishtiimport DESTINATION ${BIN_INSTALL_DIR})





