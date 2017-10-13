//===========================================
//  Lumina-desktop source code
//  Copyright (c) 2017, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
// This is the base C++ object that is used to pass information to the QML "RootDesktop" object
//===========================================
#ifndef _LUMINA_DESKTOP_ROOT_DESKTOP_OBJECT_H
#define _LUMINA_DESKTOP_ROOT_DESKTOP_OBJECT_H

#include "ScreenObject.h"
class RootDesktopObject : public QObject{
	Q_OBJECT
	//Define all the QML Properties here (interface between QML and the C++ methods below)
	Q_PROPERTY( QList<ScreenObject*> screens READ screens NOTIFY screensChanged)

public:
	//main contructor/destructor
	RootDesktopObject(QObject *parent = 0);
	~RootDesktopObject();

	static void RegisterType(){ qmlRegisterType<RootDesktopObject>("Lumina.Backend.RootDesktopObject",2,0, "RootDesktopObject");

	//primary interface to fetch the current instance of the class (so only one is running at any given time)
	static RootDesktopObject* instance();

	//QML Read Functions
	QList<ScreenObject*> screens();

	//QML Access Functions
	Q_INVOKABLE void logout();

private:
	QList<ScreenObject*> s_objects;

public slots:
	void updateScreens(); //rescan/update screen objects

private slots:

signals:
	void screensChanged();

};
#endif