
#include "UwpSdkIncludes.h"

#ifdef XWR_SYNTAX_CHECK

int main(int, char**) {
    return 0;
}

#else

#include <winrt/base.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Core.h>

using namespace winrt;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;

struct StartupView :
    implements<StartupView, IFrameworkViewSource, IFrameworkView> {

    IFrameworkView CreateView() {
        return *this;
    }

    void Initialize(CoreApplicationView const&) {}

    void SetWindow(CoreWindow const& window) {
        window.Activate();
    }

    void Load(hstring const&) {}

    void Run() {
        CoreWindow window = CoreWindow::GetForCurrentThread();

        while (true) {
            window.Dispatcher().ProcessEvents(
                CoreProcessEventsOption::ProcessOneAndAllPending);
        }
    }

    void Uninitialize() {}
};

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    winrt::init_apartment();
    CoreApplication::Run(winrt::make<StartupView>());
    return 0;
}

#endif
