#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ButtonForPullingSelectedVoiceFromHardware :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	VoiceSlotsComponent& slotsComponent;
	UnexposedParameters* unexposedParams;
	Label& nameEditor;

public:

	ButtonForPullingSelectedVoiceFromHardware() = delete;

	ButtonForPullingSelectedVoiceFromHardware(VoiceSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedVoiceFromHardware)
};
