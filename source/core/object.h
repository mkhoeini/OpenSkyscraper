#ifndef OSS_CORE_OBJECT_H
#define OSS_CORE_OBJECT_H

#include "external.h"
#include "updatable.h"


namespace OSS {
	namespace Core {
		class Object : public Base::Object, public Updatable {
		};
	}
}


#endif