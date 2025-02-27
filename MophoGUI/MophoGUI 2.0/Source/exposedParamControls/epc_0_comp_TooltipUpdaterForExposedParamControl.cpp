#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TooltipUpdaterForExposedParamControl::TooltipUpdaterForExposedParamControl(
    const uint8 paramIndex, SettableTooltipClient& clientComponent, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    paramIndex{ paramIndex },
    clientComponent{ clientComponent },
    state{ exposedParams->state.get() },
    info{ exposedParams->info.get() }
{
    auto paramID{ info->IDfor(paramIndex) };
    paramAsValue = state->getParameterAsValue(paramID);
    paramAsValue.addListener(this);

    shouldShowDescriptionAsValue = unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    shouldShowCurrentChoiceAsValue = unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
    shouldShowCurrentChoiceAsValue.addListener(this);

    updateTooltip();
}

void TooltipUpdaterForExposedParamControl::updateTooltip() {
    auto tip{ generateTooltipText() };
    clientComponent.setTooltip(tip);
}

String TooltipUpdaterForExposedParamControl::generateTooltipText() {
    auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
    auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
    String tip{ "" };
    if (shouldShowDescription)
        tip += info->descriptionFor(paramIndex) + "\n";
    if (shouldShowCurrentChoice) {
        auto paramID{ info->IDfor(paramIndex) };
        auto paramPtr{ state->getParameter(paramID) };
        auto currentChoice{ roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
        auto choiceName{ info->verboseChoiceNameFor((uint8)currentChoice, paramIndex) };
        tip += "Current Setting: " + choiceName;
    }
    return tip;
}

void TooltipUpdaterForExposedParamControl::valueChanged(Value& /*value*/) {
    updateTooltip();
}

TooltipUpdaterForExposedParamControl::~TooltipUpdaterForExposedParamControl() {
    paramAsValue.removeListener(this);
    shouldShowDescriptionAsValue.removeListener(this);
    shouldShowCurrentChoiceAsValue.removeListener(this);
}
