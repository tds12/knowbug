// 設定の読み込みと管理

#pragma once

#include "main.h"
#include <Windows.h>

#include <string>
#include <array>
#include <map>
#include <memory>
#include "module/strf.h"
#include "module/Singleton.h"

#include <functional>
#include "ExVardataString.h"

namespace Detail
{
	struct moduleDeleter { using pointer = HMODULE; void operator()(HMODULE p) { FreeLibrary(p); } };
};
//RAII for Dll
using moduleHandle_t = std::unique_ptr<HMODULE, Detail::moduleDeleter>;

struct KnowbugConfig : public Singleton<KnowbugConfig>
{
	friend class Singleton<KnowbugConfig>;
public:
	using VswInfo = std::tuple<moduleHandle_t, addVarUserdef_t, addValueUserdef_t>;

public:
	//properties from ini (see that for detail)

	string commonPath;
	bool bTopMost;
	int  initialTab;
	int  tabwidth;
	int  maxlenVarinfo, infiniteNest;
	bool showsVariableAddress, showsVariableSize, showsVariableDump;
	bool bResultNode;
	bool bCustomDraw;
	std::array<COLORREF, HSPVAR_FLAG_USERDEF> clrText;
	std::map<string, COLORREF> clrTextExtra;
	std::map<string, VswInfo> vswInfo;
	string logPath;
	int  logMaxlen;
	bool warnsBeforeClearingLog;

private:
	KnowbugConfig();

public:
	//to jusitify existent codes (such as g_config->property)
	class SingletonAccessor {
	public:
		void initialize() { instance(); }
		KnowbugConfig* operator->() { return &instance(); }
	};
};

extern KnowbugConfig::SingletonAccessor g_config;

static bool usesResultNodes() { return g_config->bResultNode; }
