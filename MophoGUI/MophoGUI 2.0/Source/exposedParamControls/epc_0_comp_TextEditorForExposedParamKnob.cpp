#include "epc_0_comp_TextEditorForExposedParamKnob.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_1_tree_InfoForExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForExposedParamKnob::TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	editorType{ info->knobTextEditorTypeFor(paramIndex) },
	paramPtr{ exposedParams->state->getParameter(info->IDfor(paramIndex)) }
{
	paramAsValue = exposedParams->state->getParameterAsValue(info->IDfor(paramIndex));
	paramAsValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForKnob.toString());
	textEditor.setFont(GUI::font_KnobValueDisplays);
	switch (editorType)
	{
	case EditorType::clockTempo:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_ClockTempo(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::lfoFrequency:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_LFO_Freq(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_PitchAndFreqRanges(); };
		break;
	case EditorType::lpfFrequency:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_LPF_Freq(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_PitchAndFreqRanges(); };
		break;
	case EditorType::oscFineTune:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_OscFineTune(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::oscPitch:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_OscPitch(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_PitchAndFreqRanges(); };
		break;
	case EditorType::oscShape:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_OscShape(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_OscShape(); };
		break;
	case EditorType::oscSlop:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_OscSlop(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::pitchBend:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_PitchBend(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::posNeg_127:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_PosNeg_127(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::pos_127:
		textEditor.onEditorShow = [this, tooltips] { onEditorShow_Pos_127(tooltips); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	default:
		break;
	}
	textEditor.onTextChange();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForExposedParamKnob::setEditorTextUsingStoredValue() {
	auto currentChoice{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
	auto currentChoiceName{ info->choiceNameFor(currentChoice, paramIndex).removeCharacters(" ") };
	if (editorType == EditorType::pitchBend)
		currentChoiceName = currentChoiceName.removeCharacters("+/-");
	textEditor.setText(currentChoiceName, dontSendNotification);
}

void TextEditorForExposedParamKnob::onEditorShow_ClockTempo(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 30 to 250)");
}

void TextEditorForExposedParamKnob::onEditorShow_LFO_Freq(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(5, "abcdefgABCDEFG0123456789#:.");
	if (tooltips->shouldShowDescription()) {
		String description{ "" };
		description += "Type in a new LFO frequency.\n";
		description += "Unsynced: " + oq + "0" + cq + ".." + oq + "89" + cq + "\n";
		description += "Pitched: " + oq + "C0" + cq + ".." + oq + "C5" + cq + " or " + oq + "90" + cq + ".." + oq + "150" + cq + "\n";
		description += "Synced: " + oq + "1:32" + cq + ".." + oq + "16:1" + cq + " or " + oq + "151" + cq + ".." + oq + "166" + cq;
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_LPF_Freq(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
	if (tooltips->shouldShowDescription()) {
		String description{ "" };
		description += "Type in either a pitch name and octave number\n";
		description += "(e.g. " + oq + "C#5" + cq + ") or a MIDI note number (e.g. " + oq + "61" + cq + ").\n";
		description += "Range: C0 (0) to G#13 (164)";
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_OscFineTune(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "-0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -50 to 50)");
}

void TextEditorForExposedParamKnob::onEditorShow_OscPitch(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
	if (tooltips->shouldShowDescription()) {
		String description{ "" };
		description += "Type in either a pitch name and octave number\n";
		description += "(e.g. " + oq + "C#5" + cq + ") or a MIDI note number (e.g. " + oq + "61" + cq + ").\n";
		description += "Range: C0 (0) to C10 (120)";
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_OscShape(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "afiopqrstwAFIOPQRSTW0123456789/");
	if (tooltips->shouldShowDescription()) {
		String description{ "" };
		description += "Type in a new shape setting.\n";
		description += "Off: " + oq + "OFF" + cq + " or " + oq + "0" + cq + "\n";
		description += "Sawtooth: " + oq + "SAW" + cq + " or " + oq + "1" + cq + "\n";
		description += "Triangle: " + oq + "TRI" + cq + " or " + oq + "2" + cq + "\n";
		description += "Sawtooth/Triangle Mix: " + oq + "S/T" + cq + " or " + oq + "3" + cq + "\n";
		description += "Square (Pulse Width 50): " + oq + "SQR" + cq + " or " + oq + "54" + cq + "\n";
		description += "Pulse Width 0..99: " + oq + "PW0" + cq + ".." + oq + "PW99" + cq + " or " + oq + "4" + cq + ".." + oq + "104" + cq;
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_OscSlop(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(1, "012345");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 5)");
}

void TextEditorForExposedParamKnob::onEditorShow_PitchBend(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(2, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 12)");
}

void TextEditorForExposedParamKnob::onEditorShow_PosNeg_127(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "-0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -127 to 127)");
}

void TextEditorForExposedParamKnob::onEditorShow_Pos_127(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 127)");
}

void TextEditorForExposedParamKnob::onTextChange_NumericRanges() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getFloatValue() };
		if (editorType == EditorType::clockTempo)
			newSetting -= 30.0f;
		if (editorType == EditorType::oscFineTune)
			newSetting += 50.0f;
		if (editorType == EditorType::posNeg_127)
			newSetting += 127.0f;
		paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForExposedParamKnob::onTextChange_PitchAndFreqRanges() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ -1.0f };
		if (newSettingString.containsAnyOf("abcdefgABCDEFG#:.")) {
			newSettingString = newSettingString.toUpperCase();
			auto numberOfChoices{ EP::numberOfChoicesForOscPitch };
			if (editorType == EditorType::lfoFrequency)
				numberOfChoices = EP::numberOfChoicesFor_LFO_Freq;
			if (editorType == EditorType::lpfFrequency)
				numberOfChoices = EP::numberOfChoicesFor_LPF_Freq;
			for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum) {
				if (info->choiceNameFor(choiceNum, paramIndex).removeCharacters(" ") == newSettingString) {
					newSetting = (float)choiceNum;
					break;
				}
			}
		}
		else
			newSetting = newSettingString.getFloatValue();
		if (newSetting > -1.0f)
			paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
		else
			setEditorTextUsingStoredValue();
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForExposedParamKnob::onTextChange_OscShape() {
	auto newSettingString{ textEditor.getText().toUpperCase() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ -1.0f };
		if (newSettingString.containsAnyOf("AFIOPQRSTW/")) {
			if (newSettingString == "OFF")
				newSetting = 0.0f;
			if (newSettingString == "SAW")
				newSetting = 1.0f;
			if (newSettingString == "TRI")
				newSetting = 2.0f;
			if (newSettingString == "S/T" || newSettingString == "ST")
				newSetting = 3.0f;
			if (newSettingString == "SQR")
				newSetting = 54.0f;
			if (newSettingString.startsWith("PW"))
				newSetting = newSettingString.fromFirstOccurrenceOf("PW", false, false).getFloatValue() + 4.0f;
		}
		else
			newSetting = newSettingString.getFloatValue();
		if (newSetting > -1.0f)
			paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
		else
			setEditorTextUsingStoredValue();
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForExposedParamKnob::showEditor() {
	textEditor.showEditor();
}

void TextEditorForExposedParamKnob::valueChanged(Value& /*value*/) {
	setEditorTextUsingStoredValue();
}

TextEditorForExposedParamKnob::~TextEditorForExposedParamKnob() {
	paramAsValue.removeListener(this);
}
