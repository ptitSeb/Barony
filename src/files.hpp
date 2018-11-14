/*-------------------------------------------------------------------------------

	BARONY
	File: files.hpp
	Desc: prototypes for file.cpp, all file access should be mediated
		  through this interface

	Copyright 2013-2016 (c) Turning Wheel LLC, all rights reserved.
	See LICENSE for details.

-------------------------------------------------------------------------------*/
#pragma once

#include <list>
#include <string>
#include <vector>
#include <cstdio>
#include <dirent.h>

 #ifdef __amigaos4__
// generic little->big conversion
template <class T> inline void littleBigEndian (T *x) {
	unsigned char *toConvert = reinterpret_cast<unsigned char *>(x);
	unsigned char tmp;
	const int sz = sizeof(T);
	for (size_t i = 0; i < sz/2; ++i) {
		tmp = toConvert[i];
		toConvert[i] = toConvert[sz - i - 1];
		toConvert[sz - i - 1] = tmp;
	}
}
#define freadBE(A, B, C, D) fread(A, B, C, D); littleBigEndian(A)
#define fwriteBE(A, B, C, D) fwrite(A, B, C, D); littleBigEndian(A)
#else
#define freadBE fread
#define fwriteBE fwrite
#endif

extern char datadir[PATH_MAX]; //PATH_MAX as defined in main.hpp -- maybe define in Config.hpp?
extern char outputdir[PATH_MAX];
void glLoadTexture(SDL_Surface* image, int texnum);
SDL_Surface* loadImage(char* filename);
voxel_t* loadVoxel(char* filename2);
int loadMap(const char* filename, map_t* destmap, list_t* entlist, list_t* creatureList, int *checkMapHash = nullptr);
int loadConfig(char* filename);
int loadDefaultConfig();
int saveMap(const char* filename);
char* readFile(char* filename);
std::list<std::string> directoryContents(const char* directory, bool includeSubdirectory, bool includeFiles);
FILE *openDataFile(const char *const filename, const char * const mode);
DIR * openDataDir(const char *const);
bool dataPathExists(const char *const);
bool completePath(char *dest, const char * const path, const char *base = datadir);
void openLogFile();
std::vector<std::string> getLinesFromDataFile(std::string filename);
int loadMainMenuMap(bool blessedAdditionMaps, bool forceVictoryMap);
int physfsLoadMapFile(int levelToLoad, Uint32 seed, bool useRandSeed, int *checkMapHash = nullptr);
std::list<std::string> physfsGetFileNamesInDirectory(const char* dir);
std::string physfsFormatMapName(char* levelfilename);
bool physfsModelIndexUpdate(int &start, int &end, bool freePreviousModels);
bool physfsSearchModelsToUpdate();
bool physfsSearchSoundsToUpdate();
void physfsReloadSounds(bool reloadAll);
void physfsReloadBooks();
bool physfsSearchBooksToUpdate();
bool physfsSearchMusicToUpdate();
void physfsReloadMusic(bool &introMusicChanged, bool reloadAll);
void physfsReloadTiles(bool reloadAll);
bool physfsSearchTilesToUpdate();
extern std::vector<int> gamemods_modelsListModifiedIndexes;
bool physfsIsMapLevelListModded();
bool physfsSearchItemSpritesToUpdate();
void physfsReloadItemSprites(bool reloadAll);
bool physfsSearchItemsTxtToUpdate();
bool physfsSearchItemsGlobalTxtToUpdate();
void physfsReloadItemsTxt();
bool physfsSearchMonsterLimbFilesToUpdate();
void physfsReloadMonsterLimbFiles();
void physfsReloadSystemImages();
bool physfsSearchSystemImagesToUpdate();
void gamemodsUnloadCustomThemeMusic();
extern std::vector<std::pair<SDL_Surface**, std::string>> systemResourceImagesToReload;

enum MapParameterIndices : int
{
	LEVELPARAM_CHANCE_SECRET,
	LEVELPARAM_CHANCE_DARKNESS,
	LEVELPARAM_CHANCE_MINOTAUR
};