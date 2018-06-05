
class CObject {
	int handler = -1;

	CObject(int modelid, double x, double y, double z, double rx, double ry, double rz, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_OBJECT_SD, float drawdistance = STREAMER_OBJECT_DD, int areaid = -1, int priority = 0);
	~CObject();

public:
	bool IsValid();
	bool SetPosition(float x, float y, float z);
	bool GetPosition(float * x, float * y, float * z);
	bool SetRotation(float rx, float ry, float rz);
	bool GetRotation(float * rx, float * ry, float * rz);
	bool SetNoCameraCol();
	bool GetNoCameraCol();
	bool Move(float x, float y, float z, float speed, float rx = -1000.0, float ry = -1000.0, float rz = -1000.0);
	bool StopMoving();
	bool IsMoving();
	bool AttachPlayerCamera(CPlayer*);
	bool AttachToObject(CObject*, float offsetx, float offsety, float offsetz, float rx, float ry, float rz, int syncrotation = 1);
	bool AttachToPlayer(CPlayer*, float offsetx, float offsety, float offsetz, float rx, float ry, float rz);
	bool AttachToVehicle(CVehicle*, float offsetx, float offsety, float offsetz, float rx, float ry, float rz);
	bool Edit(CPlayer*);
	bool IsMaterialUsed(int materialindex);
	bool GetMaterial(int materialindex, int * modelid, char txdname[], char texturename[], int * materialcolor, int maxtxdname, int maxtexturename);
	bool SetMaterial(int materialindex, int modelid, const char txdname[], const char texturename[], int materialcolor = 0);
	bool IsMaterialTextUsed(int materialindex);
	bool GetMaterialText(int materialindex, char text[], int * materialsize, char fontface[], int * fontsize, int * bold, int * fontcolor, int * backcolor, int * textalignment, int maxtext, int maxfontface);
	bool SetMaterialText(int materialindex, const char text[], int materialsize = OBJECT_MATERIAL_SIZE_256x128, const char fontface[] = "Arial", int fontsize = 24, int bold = 1, int fontcolor = 0xFFFFFFFF, int backcolor = 0, int textalignment = 0);
};