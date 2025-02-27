#include "widget_global_SliderForSettingPedalController.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingPedalController::SliderForSettingPedalController(UnexposedParameters* unexposedParams, int pedalNumber) :
	BaseSliderForSettingControllerNumber{ unexposedParams, pedalNumber == 1 ? ID::global_Pedal1ControllerNumber : ID::global_Pedal2ControllerNumber },
	unexposedParams{ unexposedParams },
	pedalNumber{ pedalNumber }
{
	jassert(pedalNumber == 1 || pedalNumber == 2);
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto paramValue{ pedalNumber == 1 ? (double)globalOptions->pedal1ControllerNumber() : (double)globalOptions->pedal2ControllerNumber() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, pedalNumber == 1 ? 4.0 : 64.0);
	setTooltip(generateTooltipString());
}

String SliderForSettingPedalController::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the MIDI controller channel that Pedal " + (String)pedalNumber + "\n";
		tooltipText += "will transmit and receive on. Range: 0 to 121.\n";
		tooltipText += "NOTE: Individual Master options are not immedi-\n";
		tooltipText += "ately updated on the hardware. Click the PUSH\n";
		tooltipText += "button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: CC #";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

SliderForSettingPedalController::~SliderForSettingPedalController() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
