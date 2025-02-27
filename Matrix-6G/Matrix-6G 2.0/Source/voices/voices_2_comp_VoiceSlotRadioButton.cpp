#include "voices_2_comp_VoiceSlotRadioButton.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

VoiceSlotRadioButton::VoiceSlotRadioButton() :
	bank{ VoicesBank::nullBank },
	slotNum{ VCS::numberOfSlotsInVoicesBank },
	slotNumString{ String(slotNum) },
	unexposedParams{ nullptr }
{
	// this default constructor is needed when initializing the vector in VoiceSlots
}

VoiceSlotRadioButton::VoiceSlotRadioButton(const VoicesBank bank, const uint8 slotNum, UnexposedParameters* unexposedParams) :
	bank{ bank },
	slotNum{ slotNum },
	slotNumString{ String(slotNum).paddedLeft('0', 2) },
	unexposedParams{ unexposedParams }
{
	auto voicesBanks{ unexposedParams->getVoicesBanks() };
	if (bank >= VoicesBank::custom_A) {
		voiceNameAsValue = voicesBanks->getVoiceNameAsValueForCustomBankSlot(bank, slotNum);
		voiceNameAsValue.addListener(this);
	}
	setRadioGroupId((int)bank + 1);
	auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipsOptions->shouldShowDescription() };
	setComponentID(ID::btn_RadioButton_VoiceSlot.toString());
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
		tip += "CTRL+C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
		tip += "CTRL+V overwrites the selected program with the settings in the\n";
		tip += "clipboard (only slots in the Custom banks can be overwritten).";
	}
	auto voiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slotNum) };
	setName(slotNumString + " - " + voiceName);
	setSize(GUI::voiceSlotRadioButtton_w, GUI::voiceAndSplitSlotRadioButtton_h);
}

void VoiceSlotRadioButton::valueChanged(Value& /*value*/) {
	auto voiceName{ voiceNameAsValue.getValue().toString() };
	setName(slotNumString + " - " + voiceName);
	repaint();
}

VoiceSlotRadioButton::~VoiceSlotRadioButton() {
	if (bank >= VoicesBank::custom_A)
		voiceNameAsValue.removeListener(this);
}
