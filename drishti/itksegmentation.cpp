#include "DrishtiConfig.h"
#include "itksegmentation.h"
#include "mopplugininterface.h"
#include <QMessageBox>

bool
ITKSegmentation::applyITKFilter(int nx, int ny, int nz,
				uchar* inVol,
				QList<Vec> seeds)
{
  //...................................
  // look in @executable_path/mopplugins
  QString sep = QDir::separator();
  QString pluginName;

  QString plugindir = QStringLiteral(DRISHTI_PLUGIN_DIR) + QDir::separator() + "mopplugins";
#if defined(Q_OS_WIN32)
  pluginName = plugindir + sep + "itkplugin.dll";
#endif
#ifdef Q_OS_MACX
  pluginName = plugindir + sep + "libitkplugin.dylib";
#endif
#if defined(Q_OS_LINUX)
  pluginName = plugindir + sep + "libitkplugin.so";
#endif

  QPluginLoader pluginLoader(pluginName);
  QObject *plugin = pluginLoader.instance();

  if (!plugin)
    {
      QMessageBox::information(0, "Error", QString("Cannot load plugin %1").\
			       arg(pluginName));
      return false;
    }  

  MopPluginInterface *pluginInterface = qobject_cast<MopPluginInterface *>(plugin);
  if (!pluginInterface)
    {
      QMessageBox::information(0, "Error", QString("Cannot load plugin interface %1").\
			       arg(pluginName));
      return false;
    }

  pluginInterface->init();
  pluginInterface->setData(nx, ny, nz, inVol, seeds);
  return pluginInterface->start();
}
