// DataTree

#include "CDataTree.h"

namespace DataTree
{

//##############################################################################
//                定義部 : CDataTree
//##############################################################################
//------------------------------------------------
// 構築
//------------------------------------------------
CDataTree::CDataTree()
	: root_(&CNodeGlobal::getInstance())
{ }

//------------------------------------------------
// 解体
//------------------------------------------------
//	CDataTree::~CDataTree() { }

/*
//------------------------------------------------
// 変数追加
// 
// @ 必要ならモジュールも追加する
//------------------------------------------------
void CDataTree::addVar( char const* name, PVal* pval )
{
	
	return;
}

//------------------------------------------------
// モジュール追加
//------------------------------------------------
void CDataTree::addModule( char const* pName, PVal* pval )
{
	
	return;
}
//*/

}
