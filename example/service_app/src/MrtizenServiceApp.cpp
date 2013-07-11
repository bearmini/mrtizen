#include "MrtizenServiceApp.h"

#include <stdexcept>

#include <mruby.h>
#include <mruby/compile.h>
#include <mrubybind.h>

using namespace Tizen::App;
using namespace Tizen::System;

MrtizenServiceApp::MrtizenServiceApp(void)
{
	SetLastResult(E_SUCCESS); // This is IMPORTANT!!  Otherwise ServiceApp::Execute() is terminating the app falsely (with wrongly complaining E_OUT_OF_MEMORY)
}

MrtizenServiceApp::~MrtizenServiceApp(void) throw()
{

}

ServiceApp*
MrtizenServiceApp::CreateInstance(void)
{
	try
	{
		// Create the instance through the constructor.
		return new MrtizenServiceApp();
	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
	}

	return null;
}

bool
MrtizenServiceApp::OnAppInitializing(AppRegistry& appRegistry)
{
	AppLogDebug("OnAppInitializing");
	bool ok = true;
	try
	{

	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
		ok = false;
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
		ok = false;
	}
	return ok;
}

extern "C"
{
    int mruby_bind_test1(int param1)
    {
        return param1 * param1;
    }
}

mrb_value
AppLogDebug_wrap(mrb_state* mrb, mrb_value self)
{
    char* message;
    int message_len;
    mrb_get_args(mrb, "s", &message, &message_len);

    AppLogDebug(message);

    return mrb_nil_value();
}

bool
MrtizenServiceApp::OnAppInitialized(void)
{
	AppLogDebug("OnAppInitialized");
	bool ok = true;
	mrb_state* mrb = mrb_open();
	try
	{
		FILE* f = fopen("/opt/apps/2ltNIw9dF5/data/mrtizen-example.rb", "r");
		if (f == NULL)
		{
			throw std::domain_error("could not load the ruby script.");
		}

        mrubybind::MrubyBind b(mrb);
        b.bind("mruby_bind_test1", mruby_bind_test1);

        mrb_define_method(mrb, mrb->kernel_module, "app_log_debug", AppLogDebug_wrap, MRB_ARGS_REQ(1));

		mrb_load_file(mrb, f);

		if (mrb->exc)
		{
			throw std::domain_error("mrb_load_file() failed.");
		}

		fclose(f);
	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
		ok = false;
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
		ok = false;
	}
	mrb_close(mrb);
	return ok;
}

bool
MrtizenServiceApp::OnAppWillTerminate(void)
{
	AppLogDebug("OnAppWillTerminate");
	bool ok = true;
	try
	{

	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
		ok = false;
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
		ok = false;
	}
	return ok;
}

bool
MrtizenServiceApp::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	AppLogDebug("OnAppTerminating");
	bool ok = true;
	try
	{

	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
		ok = false;
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
		ok = false;
	}
	return ok;
}

void
MrtizenServiceApp::OnLowMemory(void)
{
	AppLogDebug("OnLowMemory");
	try
	{

	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
	}
}

void
MrtizenServiceApp::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	AppLogDebug("OnBatteryLevelChanged");
	try
	{

	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
	}
}

