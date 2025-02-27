#include <JuceHeader.h>
#include "core_MainComponent.h"

#include "gui/gui_Colors.h"



class StandaloneApplication :
    public JUCEApplication
{
public:
    class MainWindow :
        public DocumentWindow
    {
    public:
        MainWindow(String name) :
            DocumentWindow(name, Color::black, DocumentWindow::closeButton)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(), true);
            setResizable(false, false);
            centreWithSize(getWidth(), getHeight());
            setVisible(true);
        }

        void closeButtonPressed() override {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

    StandaloneApplication() {
    }

    const String getApplicationName() override {
        return ProjectInfo::projectName;
    }

    const String getApplicationVersion() override {
        return ProjectInfo::versionString;
    }

    bool moreThanOneInstanceAllowed() override {
        return true;
    }

    void initialise(const String& /*commandLine*/) override {
        mainWindow.reset(new MainWindow(getApplicationName()));
    }

    void shutdown() override {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override {
        quit();
    }

    void anotherInstanceStarted(const String& /*commandLine*/) override {
    }

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION(StandaloneApplication)
