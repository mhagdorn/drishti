#ifndef VOLUMEFILEMANAGER_H
#define VOLUMEFILEMANAGER_H

#include "commonqtclasses.h"

#include <QProgressDialog>
#include <QStringList>
#include <QFile>

class VolumeFileManager
{
 public :
  VolumeFileManager();
  ~VolumeFileManager();
  
  enum VoxelType
  {
    _UChar = 0,
    _Char,
    _UShort,
    _Short,
    _Int,
    _Float
  };

  void reset();

  QString fileName();
  bool exists();

  void setMemMapped(bool);
  bool isMemMapped();

  void setFilenameList(QStringList);
  void setBaseFilename(QString);
  void setHeaderSize(int);
  void setSlabSize(int);
  void setVoxelType(int);

  void setDepth(int);
  void setWidth(int);
  void setHeight(int);
  void createFile(bool, bool writeData=false);

  int depth();
  int width();
  int height();

  int voxelType();
  int readVoxelType();

  void removeFile();

  uchar* getSlice(int);
  uchar* getWidthSlice(int);
  uchar* getHeightSlice(int);

  void setSlice(int, uchar*);
  void setWidthSlice(int, uchar*);
  void setHeightSlice(int, uchar*);

  uchar* rawValue(int, int, int);
  uchar* interpolatedRawValue(float, float, float);

  void startBlockInterpolation();
  void endBlockInterpolation();
  uchar* blockInterpolatedRawValue(float, float, float);

  void loadMemFile();
  void saveMemFile();
  uchar* getSliceMem(int);
  void setSliceMem(int, uchar*);
  uchar* getWidthSliceMem(int);
  void setWidthSliceMem(int, uchar*);
  uchar* getHeightSliceMem(int);
  void setHeightSliceMem(int, uchar*);
  uchar* rawValueMem(int, int, int);

  uchar* memVolDataPtr() { return m_volData; }

 private :
  bool m_memmapped;
  bool m_memChanged;
  QString m_baseFilename;
  QStringList m_filenames;
  qint64 m_header, m_slabSize;
  int m_depth, m_width, m_height;
  int m_voxelType;
  qint64 m_bytesPerVoxel;
  uchar *m_slice;
  uchar *m_block;
  int m_blockSlices, m_startBlock, m_endBlock;

  QFile m_qfile;
  QString m_filename;
  int m_slabno, m_prevslabno;  

  uchar *m_volData;

  void readBlocks(int);

  void createMemFile();  
};

#endif
