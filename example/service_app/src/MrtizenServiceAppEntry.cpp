/**
 * This file contains the Tizen C++ application entry point.
 */
#include "MrtizenServiceApp.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

_EXPORT_ int OspMain(int argc, char *pArgv[]);

/**
 * The entry function of Tizen C++ application called by the operating system.
 */
int
OspMain(int argc, char *pArgv[])
{
	result r = E_SUCCESS;
	ArrayList* pArgs = null;
	try
	{
		AppLog("Application started.");
		pArgs = new ArrayList(SingleObjectDeleter);
		pArgs->Construct();
		for (int i = 0; i < argc; i++)
		{
			pArgs->Add(*(new String(pArgv[i])));
		}

		r = Tizen::App::ServiceApp::Execute(MrtizenServiceApp::CreateInstance, pArgs);
		if (IsFailed(r))
		{
			AppLogException("Application execution failed-[%s].", GetErrorMessage(r));
			r &= 0x0000FFFF;
		}

		AppLog("Application finished.");
	}
	catch (std::exception& exc)
	{
		AppLogException(exc.what());
	}
	catch (...)
	{
		AppLogException("Unknown exception occurred.");
	}

	if (pArgs != null)
	{
		pArgs->RemoveAll(true);
		delete pArgs;
	}
	return static_cast<int>(r);
}
#ifdef __cplusplus
}
#endif // __cplusplus

