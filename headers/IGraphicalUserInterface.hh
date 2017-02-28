#ifndef IGRAPHICALUSERINTERFACE_HH_
# define IGRAPHICALUSERINTERFACE_HH_

class IGraphicalUserInterface
{
public:
	virtual int init() = 0;
	virtual int createWindow() = 0;
};

#endif