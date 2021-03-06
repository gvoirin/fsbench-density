// 7zip/Far/Plugin.h

#ifndef __7ZIP_FAR_PLUGIN_H
#define __7ZIP_FAR_PLUGIN_H

#include "Common/MyCom.h"

#include "Windows/COM.h"
#include "Windows/FileFind.h"
#include "Windows/PropVariant.h"

#include "../Agent/IFolderArchive.h"

#include "FarUtils.h"

const UInt32 kNumInfoLinesMax = 64;

class CPlugin
{
  NWindows::NCOM::CComInitializer m_ComInitializer;
  UString m_CurrentDir;

  UString m_PannelTitle;
  
  InfoPanelLine m_InfoLines[kNumInfoLinesMax];

  char m_FileNameBuffer[1024];
  char m_CurrentDirBuffer[1024];
  char m_PannelTitleBuffer[1024];

  AString PanelModeColumnTypes;
  AString PanelModeColumnWidths;
  PanelMode PanelMode;
  void AddColumn(PROPID aPropID);

  void EnterToDirectory(const UString &dirName);
  void GetPathParts(UStringVector &pathParts);
  void GetCurrentDir();
public:
  UString m_FileName;
  NWindows::NFile::NFind::CFileInfoW m_FileInfo;

  CMyComPtr<IInFolderArchive> m_ArchiveHandler;
  CMyComPtr<IFolderFolder> _folder;
  
  UString _archiveTypeName;

  bool PasswordIsDefined;
  UString Password;

  CPlugin(const UString &fileName, IInFolderArchive *archiveHandler, UString archiveTypeName);
  ~CPlugin();

  void ReadPluginPanelItem(PluginPanelItem &panelItem, UInt32 itemIndex);

  int GetFindData(PluginPanelItem **panelItems,int *itemsNumber,int opMode);
  void FreeFindData(PluginPanelItem *panelItem,int ItemsNumber);
  int SetDirectory(const char *aszDir, int opMode);
  void GetOpenPluginInfo(struct OpenPluginInfo *info);
  int DeleteFiles(PluginPanelItem *panelItems, int itemsNumber, int opMode);

  HRESULT ExtractFiles(
      bool decompressAllItems,
      const UInt32 *indices,
      UInt32 numIndices,
      bool silent,
      NExtract::NPathMode::EEnum pathMode,
      NExtract::NOverwriteMode::EEnum overwriteMode,
      const UString &destPath,
      bool passwordIsDefined, const UString &password);

  NFar::NFileOperationReturnCode::EEnum GetFiles(struct PluginPanelItem *panelItem, int itemsNumber,
      int move, char *destPath, int opMode);
  
  NFar::NFileOperationReturnCode::EEnum GetFilesReal(struct PluginPanelItem *panelItems,
      int itemsNumber, int move, const char *_aDestPath, int opMode, bool showBox);

  NFar::NFileOperationReturnCode::EEnum PutFiles(struct PluginPanelItem *panelItems, int itemsNumber,
      int move, int opMode);

  HRESULT ShowAttributesWindow();

  int ProcessKey(int key, unsigned int controlState);
};

HRESULT CompressFiles(const CObjectVector<PluginPanelItem> &pluginPanelItems);

#endif
