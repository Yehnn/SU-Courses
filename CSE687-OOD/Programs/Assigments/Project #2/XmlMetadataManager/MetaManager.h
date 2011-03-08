#ifndef META_MANAGER_H
#define META_MANAGER_H


#include "IIncludes.h"
#include "MetaGenerator.h"
#include <iostream>


class MetaManager
{
public:
	MetaManager(IInclude* iInc, IMetaGenerator* metaGen, std::iostream* stream);
private:
	IInclude* inc;
	IMetaGenerator* gen;
	std::istream* inStream;
};


inline MetaManager::MetaManager(IInclude* iInc, IMetaGenerator* metaGen, std::iostream* stream)
:inc(iInc),gen(metaGen),inStream(stream)
{

}

#endif