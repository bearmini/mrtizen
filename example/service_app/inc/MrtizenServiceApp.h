#ifndef _MRTIZEN_SERVICE_APP_H_
#define _MRTIZEN_SERVICE_APP_H_

#include <FApp.h>
#include <FBase.h>

/**
 * [MrtizenServiceApp] ServiceApp must inherit from ServiceApp class
 * which provides basic features necessary to define an ServiceApp.
 */
class MrtizenServiceApp
	: public Tizen::App::ServiceApp
{
public:
	static Tizen::App::ServiceApp* CreateInstance(void);

	MrtizenServiceApp(void);
	~MrtizenServiceApp(void) throw();

	// ServiceApp
	bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);
	bool OnAppInitialized(void);
	bool OnAppWillTerminate(void);
	bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);
	void OnLowMemory(void);
	void OnBatteryLevelChanged(Tizen::System::BatteryLevel batteryLevel);
};

#endif // _MRTIZEN_SERVICE_APP_H_
