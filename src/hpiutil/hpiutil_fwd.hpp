
#pragma once

#include <Windows.h>
#include "hspsdk/hsp3plugin.h"
#undef stat

namespace hpiutil {

static size_t const ArrayDimMax = 4;

//static char const* const BracketIdxL = "(";
//static char const* const BracketIdxR = ")";

static int const HSPVAR_FLAG_COMOBJ = HSPVAR_FLAG_COMSTRUCT;
static int const HSPVAR_FLAG_VARIANT = 7;

using vartype_t = unsigned short;
using varmode_t = signed short;
using label_t = unsigned short const*; // a.k.a. HSPVAR_LABEL
using csptr_t = unsigned short const*;
using stdat_t = STRUCTDAT const*;
using stprm_t = STRUCTPRM const*;

// HspVarProcの演算関数
using operator_t = void(*)(PDAT*, void const*);

// デバッグウィンドウのコールバック関数
using debug_callback_t = BOOL(CALLBACK*)(HSP3DEBUG*, int, int, int);

// デバッグウィンドウへの通知ID
enum DebugNotice
{
	DebugNotice_Stop = 0,
	DebugNotice_Logmes = 1,
};

// 定数 /MPTYPE_(\w+)/ の値に対応する適当な名前を得る
extern char const* nameFromMPType(int mptype);

// モジュールクラス名を得る (クローンなら末尾に `&` をつける)
extern std::string nameFromModuleClass(stdat_t stdat, bool isClone);

/**
エイリアスの名前を得る
index はそのエイリアスの元の引数列における番号。
DInfo からみつからなければ "(i)" が返る。
//*/
extern std::string nameFromStPrm(stprm_t stprm, int index);

/**
ラベル名を得る
DInfo からみつからなければ "label(%p)" が返る
//*/
extern std::string nameFromLabel(label_t lb);

//文字列リテラル
extern std::string literalFormString(char const* s);

//配列添字の文字列の生成
extern std::string stringifyArrayIndex(std::vector<int> const& indexes);

//修飾子を取り除いた識別子
extern std::string nameExcludingScopeResolution(std::string const& name);

}
