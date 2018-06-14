#pragma once
#include <string>
#include "Submesh.h"
#include "Physics.h"

using namespace std;

#ifdef WIN32
#include <Rpc.h>
#else
#include <uuid/uuid.h>
#endif

//credit for this platform independent generation goes to https://stackoverflow.com/users/196807/ubik
std::string newUUID()
{
#ifdef WIN32
	UUID uuid;
	UuidCreate(&uuid);

	unsigned char * str;
	UuidToStringA(&uuid, &str);

	std::string s((char*)str);

	RpcStringFreeA(&str);
#else
	uuid_t uuid;
	uuid_generate_random(uuid);
	char s[37];
	uuid_unparse(uuid, s);
#endif
	return s;
}

class BXDA {
public:
	BXDA();
	~BXDA();

private:
	unsigned int Version;		//Version is just 1;
	string GUID = newUUID();	//GUID
	Physics physics;			//physical properties
	Submesh* meshes;			//visual mesh - contains surface
	Submesh* colliders;			//collider mesh - contains surface
};