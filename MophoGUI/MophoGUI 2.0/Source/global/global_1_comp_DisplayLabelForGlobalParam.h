#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

class GlobalOptions;
class UnexposedParameters;

class DisplayLabelForGlobalParameter :
	public Component,
	public Value::Listener
{
	GlobalParamDisplayLabelType labelType;
	GlobalOptions* global;
	Label label_GlobalParam;
	Value globalParamAsValue;
	Value shouldShowDescriptionAsValue;

public:
	DisplayLabelForGlobalParameter() = delete;

	DisplayLabelForGlobalParameter(GlobalParamDisplayLabelType labelType, UnexposedParameters* unexposedParams);
	void setTextAccordingToParameterSetting();
	void updateTooltip();
	void valueChanged(Value& value) override;
	~DisplayLabelForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForGlobalParameter)
};