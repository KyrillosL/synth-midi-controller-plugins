#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../midi/midi_GlobalOptionsDataMessage.h"
#include "../midi/midi_RawDataTools.h"
#include "../global/global_GlobalOptionsComponent.h"
#include "../global/global_SysExIsOffWarningComponent.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoicesBanksComponent.h"
#include "../splits/splits_SplitsComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickEdit{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForPullingVoiceFromHardware{ unexposedParams },
    button_ForPushingVoiceToHardware{ exposedParams, unexposedParams },
    button_ForShowingVoicesBanksComponent{ unexposedParams },
    button_ForShowingSplitsComponent{ unexposedParams },
    button_ForShowingGlobalOptionsComponent{ unexposedParams },
    button_ForGoingToWebSite{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickEdit);
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForPullingVoiceFromHardware);
    addAndMakeVisible(button_ForPushingVoiceToHardware);
    addAndMakeVisible(button_ForShowingVoicesBanksComponent);
    button_ForShowingVoicesBanksComponent.onClick = [this] { showVoicesBanksComponent(); };
    addAndMakeVisible(button_ForShowingSplitsComponent);
    button_ForShowingSplitsComponent.onClick = [this] { showSplitsComponent(); };
    addAndMakeVisible(button_ForShowingGlobalOptionsComponent);
    button_ForShowingGlobalOptionsComponent.onClick = [this] { prepareToShowGlobalOptionsComponent(); };
    button_ForGoingToWebSite.setComponentID(ID::component_HyperlinkButton.toString());
    button_ForGoingToWebSite.setTooltip("Click to go to programming.mr1234.com");
    addAndMakeVisible(button_ForGoingToWebSite);
    setSize(GUI::editor_w, GUI::editor_h);
}

void ButtonsLayer::showVoicesBanksComponent() {
    voicesBanksComponent.reset(new VoicesBanksComponent(exposedParams, unexposedParams));
    if (voicesBanksComponent != nullptr) {
        addAndMakeVisible(voicesBanksComponent.get());
        voicesBanksComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::showSplitsComponent() {
    auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto switchToSplitModeMessage{ RawSysExDataVector::createSwitchToSplitModeMessage() };
    outgoingMidiBuffers->addDataMessage(switchToSplitModeMessage);

    splitsComponent.reset(new SplitsComponent(unexposedParams));
    if (splitsComponent != nullptr) {
        addAndMakeVisible(splitsComponent.get());
        splitsComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::prepareToShowGlobalOptionsComponent() {
    auto global{ unexposedParams->globalOptions_get() };
    global->resetAllOptionsToDefaults();
    auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    GlobalOptionsDataMessage::addRequestForGlobalOptionsDataToOutgoingMidiBuffers(outgoingMidiBuffers);
    callAfterDelay(300, [this, global] {
        if (global->sysExEnabled())
            showGlobalOptionsComponent();
        else showSysExIsOffWarningComponent();
     });
}

void ButtonsLayer::showSysExIsOffWarningComponent() {
    sysExIsOffWarningComponent.reset(new SysExIsOffWarningComponent(unexposedParams));
    if (sysExIsOffWarningComponent != nullptr) {
        addAndMakeVisible(sysExIsOffWarningComponent.get());
        sysExIsOffWarningComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::showGlobalOptionsComponent() {
    globalOptionsComponent.reset(new GlobalOptionsComponent(unexposedParams));
    if (globalOptionsComponent != nullptr) {
        addAndMakeVisible(globalOptionsComponent.get());
        globalOptionsComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForActivatingQuickEdit.setBounds(GUI::bounds_MainWindowQuickEditButton);
    button_ForPerformingUndo.setBounds(GUI::bounds_MainWindowUndoButton);
    button_ForPerformingRedo.setBounds(GUI::bounds_MainWindowRedoButton);
    button_ForPullingVoiceFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingVoiceToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingVoicesBanksComponent.setBounds(GUI::bounds_MainWindowVoicesButton);
    button_ForShowingSplitsComponent.setBounds(GUI::bounds_MainWindowSplitsButton);
    button_ForShowingGlobalOptionsComponent.setBounds(GUI::bounds_MainWindowGlobalOptionsButton);
    button_ForGoingToWebSite.setBounds(GUI::bounds_MainWindowWebLinkButton);
}

ButtonsLayer::~ButtonsLayer() {
    globalOptionsComponent = nullptr;
    sysExIsOffWarningComponent = nullptr;
    splitsComponent = nullptr;
    voicesBanksComponent = nullptr;
}
