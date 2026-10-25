
#include "UwpSdkIncludes.h"
#include "App.h"

#ifdef XWR_SYNTAX_CHECK

int main(int, char**) {
    return xwr::App::Main();
}

#else

#include <winrt/base.h>
#include <winrt/Windows.ApplicationModel.Core.h>

using namespace winrt;
using namespace Windows::ApplicationModel::Core;

struct StartupView : implements<StartupView, IFrameworkViewSource, IFrameworkView> {
    IFrameworkView CreateView() {
        return *this;
    }

    void Initialize(CoreApplicationView const&) {}
    void SetWindow(Windows::UI::Core::CoreWindow const& window) {
        window.Activate();
    }
    void Load(hstring const&) {}
    void Run() {
        xwr::App::Main();
    }
    void Uninitialize() {}
};

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    winrt::init_apartment();
    CoreApplication::Run(winrt::make<StartupView>());
    return 0;
}

#endif
