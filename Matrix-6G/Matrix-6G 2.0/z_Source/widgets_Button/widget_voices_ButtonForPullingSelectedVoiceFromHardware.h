#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ButtonForPullingSelectedVoiceFromHardware :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	VoiceSlotsComponent& voiceSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForPullingSelectedVoiceFromHardware() = delete;

	ButtonForPullingSelectedVoiceFromHardware(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedVoiceFromHardware)
};
