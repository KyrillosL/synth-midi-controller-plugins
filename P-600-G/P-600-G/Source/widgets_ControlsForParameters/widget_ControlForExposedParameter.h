#pragma once

#include "../widgets_Slider/widget_KnobForPitchWithValueStringDisplay.h"
#include "../widgets_Slider/widget_KnobWithValueStringDisplay.h"
#include "../widgets_Slider/widget_SwitchSliderWithExposedParamAttacher.h"



class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobForPitchWithValueStringDisplay> knobForPitchWithValueStringDisplay;
	std::unique_ptr<SwitchSliderWithExposedParamAttacher> twoPoleSwitchWithExposedParamAttacher;
	std::unique_ptr<SwitchSliderWithExposedParamAttacher> threePoleSwitchWithExposedParamAttacher;

	ControlForExposedParameter();

public:
	ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams);

private:
	void buildKnobWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildKnobForPitchWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildTwoPoleSwitchControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildThreePoleSwitchControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);

public:
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const;
	void deleteAttachment() const;
	~ControlForExposedParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};