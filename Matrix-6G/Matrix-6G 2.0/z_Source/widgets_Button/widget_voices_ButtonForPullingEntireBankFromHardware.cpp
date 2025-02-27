#include "widget_voices_ButtonForPullingEntireBankFromHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingEntireBankFromHardware::ButtonForPullingEntireBankFromHardware(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::customA)
		setComponentID(ID::button_PullCustomBankA.toString());
	if (bank == VoicesBank::customB)
		setComponentID(ID::button_PullCustomBankB.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingEntireBankFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull all the patches stored in the Matrix-6R\n";
		buttonTooltip += "hardware into this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingEntireBankFromHardware::onClickMethod() {
}
