SET(common_SOURCES
  ../../mainwindowui.cpp 
  ../../cropobject.cpp 
  ../../pathobject.cpp 
  ../../dcolordialog.cpp 
  ../../dcolorwheel.cpp 
  ../../propertyeditor.cpp 
  ../../staticfunctions.cpp 
  ../../volumefilemanager.cpp 
  ../../volumeinformation.cpp 
  ../../gradienteditorwidget.cpp 
  ../../gradienteditor.cpp 
  ../../classes.cpp 
  ../../matrix.cpp 
  ../../global.cpp )

SET(common_HEADERS 
  ../../mainwindowui.h 
  ../../cropobject.h 
  ../../pathobject.h 
  ../../dcolordialog.h 
  ../../dcolorwheel.h 
  ../../propertyeditor.h 
  ../../staticfunctions.h 
  ../../volumefilemanager.h 
  ../../volumeinformation.h 
  ../../gradienteditorwidget.h 
  ../../gradienteditor.h 
  ../../classes.h 
  ../../matrix.h 
  ../../global.h   )

SET(common_FORMS ../../propertyeditor.ui)

QT5_WRAP_CPP(common_HEADERS_MOC ${common_HEADERS})
QT5_WRAP_UI(common_FORMS_HEADERS ${common_FORMS})

ADD_LIBRARY(common STATIC ${common_SOURCES})
SET_TARGET_PROPERTIES( common PROPERTIES COMPILE_FLAGS -fPIC)
qt5_use_modules(common Widgets Xml OpenGL)
