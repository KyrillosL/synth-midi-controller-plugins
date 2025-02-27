#include "params_ExposedParamsInfo_Singleton.h"

#include "params_IntToContextualStringConverters.h"
#include "params_RangeTypes.h"
#include "../gui/gui_Constants.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	String descriptionString;

	//======================================================

	for (uint8 i = 1; i != 3; ++i) {
		identifiers.add("osc" + (String)i + "_Pitch");
		exposedNames.add("Oscillator " + (String)i + " Pitch");
		paramNumbers.add(i == 1 ? (uint8)0 : (uint8)10);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySliderForPitch);
		converters.add(IntToOscPitchString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(0);
		descriptionString =  "Sets oscillator " + (String)i + GUI::apostrophe + "s base pitch in semitone steps.\n";
		descriptionString += "Range: 0 (C 0) to 63 (D# 5). Hold down the\n";
		descriptionString += "SHIFT key when using the mouse wheel to incre-\n";
		descriptionString += "ment the pitch by one octave (12 semitones).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow1_y));
		dataByteIndices.add(i == 1 ? (uint16)1 : (uint16)6);

		identifiers.add("osc" + (String)i + "_Type");
		exposedNames.add("Oscillator " + (String)i + " Type");
		paramNumbers.add(i == 1 ? (uint8)6 : (uint8)16);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToOscTypeString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add(i == 1 ? (uint8)3 : (uint8)4);
		defaultValues.add(i == 1 ? (uint8)2 : (uint8)1);
		descriptionString =  "Selects oscillator " + (String)i + GUI::apostrophe + "s wave type.\n";
		descriptionString += "OFF: The oscillator produces no sound.\n";
		descriptionString += "PULSE: Set the width of the pulse below.\n";
		descriptionString += "WAVE: Set the shape of the wave below.\n";
		descriptionString += "BOTH: A blend of pulse and wave.";
		if (i == 2)
			descriptionString += "\nNOISE: White noise (oscillator 2 only).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow2_y));
		dataByteIndices.add(i == 1 ? (uint16)5 : (uint16)10);

		identifiers.add("osc" + (String)i + "_PulseWidth");
		exposedNames.add("Oscillator " + (String)i + " Pulse Width");
		paramNumbers.add(i == 1 ? (uint8)3 : (uint8)13);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(i == 1 ? (uint8)31 : (uint8)24);
		descriptionString =  "Sets the width of oscillator " + (String)i + GUI::apostrophe + "s\n";
		descriptionString += "wave when its type is set to pulse.\n";
		descriptionString += "Range: 0 (very wide) to 63 (very narrow).\n";
		descriptionString += "A value of 31 produces a square wave.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow3_y));
		dataByteIndices.add(i == 1 ? (uint16)3 : (uint16)8);

		identifiers.add("osc" + (String)i + "_SawTri");
		exposedNames.add("Oscillator " + (String)i + " Saw / Triangle Wave");
		paramNumbers.add(i == 1 ? (uint8)5 : (uint8)15);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add((uint8)31);
		descriptionString =  "Sets the shape of oscillator " + (String)i + "\n";
		descriptionString += "when its type is set to wave.\n";
		descriptionString += "Range: 0 (sawtooth) to 63 (triangle).\n";
		descriptionString += "Intermediate values produce various\n";
		descriptionString += "mixtures of the two shapes.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow4_y));
		dataByteIndices.add(i == 1 ? (uint16)2 : (uint16)7);

		if (i == 1) {
			identifiers.add("osc1_Sync");
			exposedNames.add("Oscillator 1 Sync");
			paramNumbers.add(i == 1 ? (uint8)2 : (uint8)12);
			isQuickEditEnabled.add((bool)true);
			controlTypes.add(ControlType::comboBox);
			converters.add(IntToOsc1SyncString::get());
			rangeTypes.add(RangeType::unsignedValue);
			maxValues.add((uint8)3);
			defaultValues.add((uint8)0);
			descriptionString =  "Selects whether and to what degree oscillator 1" + GUI::apostrophe + "s\n";
			descriptionString += "waveform is synchronized with that of oscillator 2.";
			descriptions.add(descriptionString);
			controlWidths.add(GUI::defaultControl_w);
			controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow5_y));
			dataByteIndices.add((uint16)17);
		}
		else {
			identifiers.add("osc2_Detune");
			exposedNames.add("Oscillator 2 Detune");
			paramNumbers.add((uint8)12);
			isQuickEditEnabled.add((bool)true);
			controlTypes.add(ControlType::rotarySlider);
			converters.add(IntToSigned6bitValueString::get());
			rangeTypes.add(RangeType::signed6bitValue);
			maxValues.add((uint8)62);
			defaultValues.add((uint8)33);
			descriptionString =  "Slightly lowers or raises Oscillator 2" + GUI::apostrophe + "s pitch.\n";
			descriptionString += "Range -31 to +31 (-/+ ~25 cents). 0 is no detune.\n";
			descriptionString += "NOTE: Negative values cannot be assigned to indi-\n";
			descriptionString += "vidual parameters via Quick Patch Edit. Use the\n";
			descriptionString += "PUSH button to send the entire patch instead.";
			descriptions.add(descriptionString);
			controlWidths.add(GUI::defaultControl_w);
			controlCenterPoints.add(Point<int>(GUI::oscControlsCol2_x, GUI::controlsRow5_y));
			dataByteIndices.add((uint16)11);
		}

		identifiers.add("osc" + (String)i + "_LFO1_FM");
		exposedNames.add("Oscillator " + (String)i + " LFO 1 FM Amount");
		paramNumbers.add(i == 1 ? (uint8)1 : (uint8)11);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToSigned7bitValueString::get());
		rangeTypes.add(RangeType::signed7bitValue);
		maxValues.add((uint8)126);
		defaultValues.add((uint8)63);
		descriptionString =  "Sets whether and to what degree LFO 1\n";
		descriptionString += "modulates the pitch of oscillator " + (String)i + ".\n";
		descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
		descriptionString += "Negative values invert the LFO waveform.\n";
		descriptionString += "NOTE: Negative values cannot be\n";
		descriptionString += "assigned to individual parameters via\n";
		descriptionString += "Quick Patch Edit. Use the PUSH button\n";
		descriptionString += "to send the entire patch instead.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow6_y));
		dataByteIndices.add(i == 1 ? (uint16)78 : (uint16)80);

		identifiers.add("osc" + (String)i + "_LFO2_PWM");
		exposedNames.add("Oscillator " + (String)i + " Pulse Width Mod. by LFO 2");
		paramNumbers.add(i == 1 ? (uint8)4 : (uint8)14);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToSigned7bitValueString::get());
		rangeTypes.add(RangeType::signed7bitValue);
		maxValues.add((uint8)126);
		defaultValues.add((uint8)63);
		descriptionString =  "Sets whether and to what degree LFO 2\n";
		descriptionString += "modulates the pulse width of oscillator " + (String)i + ".\n";
		descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
		descriptionString += "Negative values invert the LFO waveform.\n";
		descriptionString += "NOTE: Negative values cannot be\n";
		descriptionString += "assigned to individual parameters via\n";
		descriptionString += "Quick Patch Edit. Use the PUSH button\n";
		descriptionString += "to send the entire patch instead.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow7_y));
		dataByteIndices.add(i == 1 ? (uint16)79 : (uint16)81);

		identifiers.add("osc" + (String)i + "_KeyClick");
		exposedNames.add("Oscillator " + (String)i + " Key Click");
		paramNumbers.add(i == 1 ? (uint8)9 : (uint8)19);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToOffOnString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)1);
		defaultValues.add((uint8)0);
		descriptionString = "Adds percussive punch to\n";
		descriptionString += "the start of the sound.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow8_y));
		dataByteIndices.add(i == 1 ? (uint16)14 : (uint16)16);

		identifiers.add("osc" + (String)i + "_KeyTrack");
		exposedNames.add("Oscillator " + (String)i + " Key Tracking");
		paramNumbers.add(i == 1 ? (uint8)8 : (uint8)18);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		if (i == 1)
			converters.add(IntToOsc1KeyTrackString::get());
		else
			converters.add(IntToOsc2AndVCFKeyTrackString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add(i == 1 ? (uint8)1 : (uint8)2);
		defaultValues.add(i == 1 ? (uint8)0 : (uint8)2);
		descriptionString =  "Selects how oscillator " + (String)i + " responds to incoming pitch\n";
		descriptionString += "change messages (e.g. notes played on a keyboard controller).\n";
		if (i == 1) {
			descriptionString += "KEYBD: Oscillater " + (String)i + GUI::apostrophe + "s pitch tracks note key changes normally.\n";
			descriptionString += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
			descriptionString += "according to the settings in the portamento (aka " + GUI::openQuote + "glide" + GUI::closeQuote + ") section.";
		}
		else {
			descriptionString += "OFF: Oscillater 2" + GUI::apostrophe + "s pitch will not change as notes are played.\n";
			descriptionString += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
			descriptionString += "according to the settings in the portamento (aka " + GUI::openQuote + "glide" + GUI::closeQuote + ") section.\n";
			descriptionString += "KEYBD: Oscillator 2" + GUI::apostrophe + "s pitch tracks note key changes normally.";
		}
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow9_y));
		dataByteIndices.add(i == 1 ? (uint16)13 : (uint16)15);

		identifiers.add("osc" + (String)i + "_LeverControl");
		exposedNames.add("Oscillator " + (String)i + " Lever Control");
		paramNumbers.add(i == 1 ? (uint8)7 : (uint8)17);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToLeverControlString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)3);
		defaultValues.add((uint8)3);
		descriptionString =  "Selects which of the performance " + GUI::openQuote + "levers" + GUI::closeQuote + "\n";
		descriptionString += "(wheel-type controllers) will modulate oscillator " + (String)i + ".\n";
		descriptionString += "OFF: Oscillator " + (String)i + " is not controlled by either lever.\n";
		descriptionString += "BEND: Pitch bend is controlled by lever 1 (pitch wheel).\n";
		descriptionString += "VIB: Vibrato amount is controlled by lever 2 (mod wheel).\n";
		descriptionString += "BOTH: Oscillator " + (String)i + " is controlled by both levers.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ? GUI::oscControlsCol1_x : GUI::oscControlsCol2_x, GUI::controlsRow10_y));
		dataByteIndices.add(i == 1 ? (uint16)4 : (uint16)9);
	}

	identifiers.add("osc_Balance");
	exposedNames.add("Oscillator Balance");
	paramNumbers.add((uint8)20);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::linearSlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Sets the relative levels of the two oscillators.\n";
	descriptionString += "Range: 0 to 63. At 63, only oscillator 1 is heard.\n";
	descriptionString += "At 0, only oscillator 2 is heard. 31 is an equal mix.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::oscBalanceControl_w);
	controlCenterPoints.add(Point<int>(GUI::oscBalanceControl_x, GUI::controlsRow11_y));
	dataByteIndices.add((uint16)12);

	//======================================================

	identifiers.add("vcf_Freq");
	exposedNames.add("VCF Cutoff Frequency");
	paramNumbers.add((uint8)21);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)127);
	defaultValues.add((uint8)55);
	descriptionString =  "Sets the base cutoff frequency of\n";
	descriptionString += "the voltage-controlled filter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow1_y));
	dataByteIndices.add((uint16)18);

	identifiers.add("vcf_Reso");
	exposedNames.add("VCF Resonance");
	paramNumbers.add((uint8)24);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString = "Sets the resonance level of\n";
	descriptionString += "the voltage-controlled filter.\n";
	descriptionString += "Range: 0 to 63. At 63, the/n";
	descriptionString += "filter will self-oscillate.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow2_y));
	dataByteIndices.add((uint16)19);

	identifiers.add("vcf_Env1Amt");
	exposedNames.add("VCF Envelope 1 Amount");
	paramNumbers.add((uint8)22);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)105);
	descriptionString =  "Sets whether and to what degree envelope 1\n";
	descriptionString += "modulates the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow3_y));
	dataByteIndices.add((uint16)82);

	identifiers.add("vcf_PressureAmt");
	exposedNames.add("VCF Pressure Amount");
	paramNumbers.add((uint8)23);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets whether and to what degree keyboard pressure \n";
	descriptionString += "(aftertouch) modulates the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the pressure response.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow4_y));
	dataByteIndices.add((uint16)83);

	identifiers.add("vcf_LeverControl");
	exposedNames.add("VCF Lever Control");
	paramNumbers.add((uint8)25);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToLeverControlString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects which of the performance " + GUI::openQuote + "levers" + GUI::closeQuote + "\n";
	descriptionString += "(wheel-type controllers) modulate the VCF frequency.\n";
	descriptionString += "OFF: VCF frequency is not controlled by either lever.\n";
	descriptionString += "BEND: VCF frequency is controlled by lever 1 (pitch wheel).\n";
	descriptionString += "VIB: VCF frequency vibrato is controlled by lever 2 (mod wheel).\n";
	descriptionString += "BOTH: VCF frequency is controlled by both levers.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow5_y));
	dataByteIndices.add((uint16)20);

	identifiers.add("vcf_KeyTrack");
	exposedNames.add("VCF Key Tracking");
	paramNumbers.add((uint8)26);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOsc2AndVCFKeyTrackString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)2);
	defaultValues.add((uint8)2);
	descriptionString =  "Selects how the VCF" + GUI::apostrophe + "s cutoff frequency responds to incoming pitch\n";
	descriptionString += "change messages (e.g. notes played on a keyboard controller).\n";
	descriptionString += "OFF: Note key changes have no effect on the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "PORTA: Tracking is active, but transitions between cutoff frequencies are\n";
	descriptionString += "smoothed according to the settings in the portamento (aka " + GUI::openQuote + "glide" + GUI::closeQuote + ") section.\n";
	descriptionString += "KEYBD: The VCF" + GUI::apostrophe + "s cutoff frequency tracks note key changes, rising as\n";
	descriptionString += "higher notes are played and dropping as lower notes are played.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow6_y));
	dataByteIndices.add((uint16)21);

	//======================================================

	identifiers.add("vca1_Volume");
	exposedNames.add("VCA 1 Volume");
	paramNumbers.add((uint8)27);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the initial output level of the\n";
	descriptionString += "first-stage voltage-controlled amplifier.\n";
	descriptionString += "Range: 0 (silence) to 63 (maximum).";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow9_y));
	dataByteIndices.add((uint16)23);

	identifiers.add("vca1_VeloAmt");
	exposedNames.add("VCA 1 Velocity Amount");
	paramNumbers.add((uint8)28);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets whether and to what degree note velocity\n";
	descriptionString += "modulates the output level of VCA 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the velocity response.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow10_y));
	dataByteIndices.add((uint16)84);

	identifiers.add("vca2_Env2Amt");
	exposedNames.add("VCA 2 Envelope 2 Amount");
	paramNumbers.add((uint8)29);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)126);
	descriptionString =  "Sets whether and to what degree envelope 2\n";
	descriptionString += "modulates the output level of the second-\n";
	descriptionString += "stage voltage-controlled amplifier.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfCol_x, GUI::controlsRow11_y));
	dataByteIndices.add((uint16)85);

	//======================================================

	identifiers.add("vcfFM_Osc1Amt");
	exposedNames.add("VCF FM By Oscillator 1 Amount");
	paramNumbers.add((uint8)30);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets whether and to what degree oscillator 1\n";
	descriptionString += "modulates the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Range: 0 (no modulation) to 63 (maximum).";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfFMcontrols_x, GUI::controlsRow1_y));
	dataByteIndices.add((uint16)22);

	identifiers.add("vcfFM_Env3Amt");
	exposedNames.add("VCF FM Envelope 3 Amount");
	paramNumbers.add((uint8)31);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets whether and to what degree envelope 3\n";
	descriptionString += "modulates the amount of VCF FM by oscillator 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfFMcontrols_x, GUI::controlsRow2_y));
	dataByteIndices.add((uint16)92);

	identifiers.add("vcfFM_PressureAmt");
	exposedNames.add("VCF FM Pressure Amount");
	paramNumbers.add((uint8)32);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets whether and to what degree keyboard\n";
	descriptionString += "pressure (aftertouch) modulates the\n";
	descriptionString += "amount of VCF FM by oscillator 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the pressure response.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::defaultControl_w);
	controlCenterPoints.add(Point<int>( GUI::vcfFMcontrols_x, GUI::controlsRow3_y));
	dataByteIndices.add((uint16)93);

	//======================================================

	identifiers.add("porta_Rate");
	exposedNames.add("Portamento Rate");
	paramNumbers.add((uint8)44);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the amount of time it takes to transition\n";
	descriptionString += "from the origin pitch to the destination pitch.\n";
	descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::portaControls_w);
	controlCenterPoints.add(Point<int>( GUI::portaControls_x, GUI::controlsRow6_y));
	dataByteIndices.add((uint16)24);

	identifiers.add("porta_Velo");
	exposedNames.add("Portamento Velocity Amount");
	paramNumbers.add((uint8)45);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets whether and to what degree note\n";
	descriptionString += "velocity modulates the portamento rate.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the velocity response.\n";
	descriptionString += "NOTE: Negative values cannot be\n";
	descriptionString += "assigned to individual parameters via\n";
	descriptionString += "Quick Patch Edit. Use the PUSH button\n";
	descriptionString += "to send the entire patch instead.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::portaControls_w);
	controlCenterPoints.add(Point<int>( GUI::portaControls_x, GUI::controlsRow7_y));
	dataByteIndices.add((uint16)91);

	identifiers.add("porta_Mode");
	exposedNames.add("Portamento Mode");
	paramNumbers.add((uint8)46);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToPortaModeString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)2);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects how the portamento transition rate is calculated.\n";
	descriptionString += "LINEAR: Linear - the time it takes to transition between\n";
	descriptionString += "two pitches is proportional to the distance between them.\n";
	descriptionString += "CONSTANT: Constant time - the time it takes to transition between\n";
	descriptionString += "two pitches is the same regardless of the distance between them.\n";
	descriptionString += "EXPO: Exponential - the transition between pitches starts out fast\n";
	descriptionString += "then slows down as it gets closer to the destination pitch.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::portaControls_w);
	controlCenterPoints.add(Point<int>( GUI::portaControls_x, GUI::controlsRow8_y));
	dataByteIndices.add((uint16)25);

	identifiers.add("porta_Legato");
	exposedNames.add("Portamento Legato Mode");
	paramNumbers.add((uint8)47);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOffOnString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When legato is on, portamento will only be active\n";
	descriptionString += "when a new note is played prior to releasing the\n";
	descriptionString += "previous note. This behavior is only active when\n";
	descriptionString += "the keyboard mode is set to unison.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::portaControls_w);
	controlCenterPoints.add(Point<int>( GUI::portaControls_x, GUI::controlsRow9_y));
	dataByteIndices.add((uint16)26);

	//======================================================

	identifiers.add("keyboard_Mode");
	exposedNames.add("Keyboard Mode");
	paramNumbers.add((uint8)48);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToKeyboardModeString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects how notes get assigned to the hardware" + GUI::apostrophe + "s six available voices.\n";
	descriptionString += "REASGN: Reassign - once a note gets assigned to a certain voice,\n";
	descriptionString += "every time thereafter that the same note is played, it will get\n";
	descriptionString += "reassigned to the same voice.\n";
	descriptionString += "ROTATE: Rotate - the hardware loops through the six voices,\n";
	descriptionString += "assigning each new note to the next available voice.\n";
	descriptionString += "UNISON: Unison (monophonic) - each note triggers all six voices\n";
	descriptionString += "and only one note at a time can play. When multiple notes are played\n";
	descriptionString += "at once, only the lowest note will be heard.\n";
	descriptionString += "REAROB: Reassign rob - like reassign mode, but if all six voices are\n";
	descriptionString += "sounding and a new note is played, the new note will " + GUI::openQuote + "rob" + GUI::closeQuote + " a voice\n";
	descriptionString += "from one of the notes that are already playing.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::portaControls_w);
	controlCenterPoints.add(Point<int>( GUI::portaControls_x, GUI::controlsRow12_y));
	dataByteIndices.add((uint16)0);

	//======================================================

	for (uint8 i = 1; i != 3; ++i) {
		identifiers.add("lfo" + (String)i + "_Speed");
		exposedNames.add("LFO " + (String)i + " Speed");
		paramNumbers.add(i == 1 ? (uint8)80 : (uint8)90);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add((uint8)i == 1 ? 40 : 30);
		descriptionString =  "Sets the cycle rate of low-frequency oscillator " + (String)i + ".\n";
		descriptionString += "Range: 0 (slowest) to 63 (fastest).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow1_y));
		dataByteIndices.add(i == 1 ? (uint16)27 : (uint16)34);

		if (i == 1) {
			identifiers.add("lfo1_PressureAmt");
			exposedNames.add("LFO 1 Pressure Amount");
			paramNumbers.add(81);
			isQuickEditEnabled.add((bool)true);
			controlTypes.add(ControlType::rotarySlider);
			converters.add(IntToSigned7bitValueString::get());
			rangeTypes.add(RangeType::signed7bitValue);
			maxValues.add((uint8)126);
			defaultValues.add((uint8)63);
			descriptionString =  "Sets whether and to what degree keyboard pressure\n";
			descriptionString += "(aftertouch) will modulate the speed of LFO 1\n";
			descriptionString += "(e.g. higher pressure increases the cycle rate).\n";
			descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
			descriptionString += "Negative values invert the pressure response.\n";
			descriptionString += "NOTE: Negative values cannot be\n";
			descriptionString += "assigned to individual parameters via\n";
			descriptionString += "Quick Patch Edit. Use the PUSH button\n";
			descriptionString += "to send the entire patch instead.";
			descriptions.add(descriptionString);
			controlWidths.add(GUI::defaultControl_w);
			controlCenterPoints.add(Point<int>( GUI::lfo1Controls_x, GUI::controlsRow5_y));
			dataByteIndices.add((uint16)94);
		}
		else {
			identifiers.add("lfo2_KeyTrackAmt");
			exposedNames.add("LFO 2 Key Tracking Amount");
			paramNumbers.add(91);
			isQuickEditEnabled.add((bool)true);
			controlTypes.add(ControlType::rotarySlider);
			converters.add(IntToSigned7bitValueString::get());
			rangeTypes.add(RangeType::signed7bitValue);
			maxValues.add((uint8)126);
			defaultValues.add((uint8)63);
			descriptionString =  "Sets whether and to what degree keyboard\n";
			descriptionString += "position will modulate the speed of LFO 2.\n";
			descriptionString += "(e.g. higher notes increase the cycle rate).\n";
			descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
			descriptionString += "Negative values invert the key position response.\n";
			descriptionString += "NOTE: Negative values cannot be\n";
			descriptionString += "assigned to individual parameters via\n";
			descriptionString += "Quick Patch Edit. Use the PUSH button\n";
			descriptionString += "to send the entire patch instead.";
			descriptions.add(descriptionString);
			controlWidths.add(GUI::defaultControl_w);
			controlCenterPoints.add(Point<int>( GUI::lfo2Controls_x, GUI::controlsRow5_y));
			dataByteIndices.add((uint16)95);
		}

		identifiers.add("lfo" + (String)i + "_WaveType");
		exposedNames.add("LFO " + (String)i + " Wave Type");
		paramNumbers.add(i == 1 ? (uint8)82 : (uint8)92);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToLFOwaveTypeString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)6);
		defaultValues.add((uint8)0);
		descriptionString =  "Selects the type of modulation signal that LFO " + (String)i + " generates.\n";
		descriptionString += "TRI: Triangle - a periodic wave that steadily rises and falls\n";
		descriptionString += "between its minimum and maximum values.\n";
		descriptionString += "UPSAW: Up (positive) sawtooth - a periodic wave that rises steadily\n";
		descriptionString += "to the maximum value then abruptly falls to the minimum value.\n";
		descriptionString += "DNSAW: Down (negative) sawtooth - a periodic wave that falls steadily\n";
		descriptionString += "to the minimum value then abruptly rises to the maximum value.\n";
		descriptionString += "SQUAR: Square - a periodic wave that switches abruptly between\n";
		descriptionString += "the minimum and maximum values.\n";
		descriptionString += "RANDM: Random - an aperiodic wave that outputs a series of random values.\n";
		descriptionString += "NOISE: Noise - a much faster version of the random waveform.\n";
		descriptionString += "SAMPL: Sampled - the LFO" + GUI::apostrophe + "s waveform is created by periodically sampling\n";
		descriptionString += "the value of another modulation source. Select the sample source below.\n";
		descriptionString += "The sampling rate is determined by the LFO" + GUI::apostrophe + "s speed setting, above.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow2_y));
		dataByteIndices.add(i == 1 ? (uint16)30 : (uint16)37);

		identifiers.add("lfo" + (String)i + "_RetrigPoint");
		exposedNames.add("LFO " + (String)i + " Retrigger Point");
		paramNumbers.add(i == 1 ? (uint8)83 : (uint8)93);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(0);
		descriptionString =  "If LFO " + (String)i + " is set (above) to be triggered by the keyboard or by\n";
		descriptionString += "an external source, modulation can be set to start from a\n";
		descriptionString += "point in the LFO" + GUI::apostrophe + "s waveform cycle other than its beginning.\n";
		descriptionString += "Range: 0 (beginning of the cycle) to 63 (the cycle" + GUI::apostrophe + "s half-way point).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow8_y));
		dataByteIndices.add(i == 1 ? (uint16)31 : (uint16)38);

		identifiers.add("lfo" + (String)i + "_Amp");
		exposedNames.add("LFO " + (String)i + " Amplitude");
		paramNumbers.add(i == 1 ? (uint8)84 : (uint8)94);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(0);
		descriptionString =  "Sets the degree to which LFO " + (String)i + " modulates its destination.\n";
		descriptionString += "Range: 0 (no modulation) to 63 (maximum modulation).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow4_y));
		dataByteIndices.add(i == 1 ? (uint16)33 : (uint16)40);

		identifiers.add("lfo" + (String)i + "_Ramp" + (String)i + "Amt");
		exposedNames.add("LFO " + (String)i + " Ramp " + (String)i + " Amount");
		paramNumbers.add(i == 1 ? (uint8)85 : (uint8)95);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToSigned7bitValueString::get());
		rangeTypes.add(RangeType::signed7bitValue);
		maxValues.add((uint8)126);
		defaultValues.add((uint8)126);
		descriptionString =  "Sets whether and to what degree ramp " + (String)i + "\n";
		descriptionString += "will modulate LFO " + (String)i + GUI::apostrophe + "s amplitude.\n";
		descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
		descriptionString += "Negative values invert the ramp.\n";
		descriptionString += "NOTE: Negative values cannot be\n";
		descriptionString += "assigned to individual parameters via\n";
		descriptionString += "Quick Patch Edit. Use the PUSH button\n";
		descriptionString += "to send the entire patch instead.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow6_y));
		dataByteIndices.add(i == 1 ? (uint16)89 : (uint16)90);

		identifiers.add("lfo" + (String)i + "_TrigMode");
		exposedNames.add("LFO " + (String)i + " Trigger Mode");
		paramNumbers.add(i == 1 ? (uint8)86 : (uint8)96);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToLFOtrigString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)3);
		defaultValues.add((uint8)0);
		descriptionString =  "Selects the type of trigger that will start LFO " + (String)i + GUI::apostrophe + "s control cycle.\n";
		descriptionString += "OFF: The LFO is not triggered and cycles freely.\n";
		descriptionString += "STRIG: Single - A new note triggers the LFO only when no other\n";
		descriptionString += "notes are currently held down (only active in unison mode).\n";
		descriptionString += "MTRIG: Multiple - the LFO is triggered with every new note played.\n";
		descriptionString += "XTRIG: External - an external signal (e.g. a footswitch) triggers the LFO.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow7_y));
		dataByteIndices.add(i == 1 ? (uint16)28 : (uint16)35);

		identifiers.add("lfo" + (String)i + "_Lag");
		exposedNames.add("LFO " + (String)i + " Lag Processing");
		paramNumbers.add(i == 1 ? (uint8)87 : (uint8)97);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToOffOnString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)1);
		defaultValues.add((uint8)0);
		descriptionString =  "The lag processor which smooths pitch transitions for portamento\n";
		descriptionString += "can also be used to smooth the value transitions in LFO " + (String)i + GUI::apostrophe + "s wave\n";
		descriptionString += "cycle. The effect is most notable on a square wave cycle.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow9_y));
		dataByteIndices.add(i == 1 ? (uint16)29 : (uint16)36);

		identifiers.add("lfo" + (String)i + "_Sample");
		exposedNames.add("LFO " + (String)i + " Sample Source");
		paramNumbers.add(i == 1 ? (uint8)88 : (uint8)98);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToLFOsampleSourceString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)20);
		defaultValues.add((uint8)9);
		descriptionString =  "Selects the modulation source that LFO " + (String)i + " will\n";
		descriptionString += "periodically sample to calculate its output value\n";
		descriptionString += "(when its wave type, above, is set to sample).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::lfo1Controls_x :  GUI::lfo2Controls_x, GUI::controlsRow3_y));
		dataByteIndices.add(i == 1 ? (uint16)32 : (uint16)39);
	}
	//======================================================

	for (uint8 i = 1; i != 3; ++i) {
		identifiers.add("ramp" + (String)i + "_Rate");
		exposedNames.add("Ramp " + (String)i + " Rate");
		paramNumbers.add(i == 1 ? (uint8)40 : (uint8)42);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add((uint8)0);
		descriptionString =  "Sets the amount of time it takes for\n";
		descriptionString += "Ramp " + (String)i + " to complete its control cycle.\n";
		descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::rampControlsCol1_x :  GUI::rampControlsCol2_x, GUI::controlsRow1_y));
		dataByteIndices.add(i == 1 ? (uint16)74 : (uint16)76);

		identifiers.add("ramp" + (String)i + "_Trig");
		exposedNames.add("Ramp " + (String)i + " Trigger");
		paramNumbers.add(i == 1 ? (uint8)41: (uint8)43);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToRampTrigString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)3);
		defaultValues.add((uint8)0);
		descriptionString =  "Selects the type of trigger that will start ramp " + (String)i + GUI::apostrophe + "s control cycle.\n";
		descriptionString += "STRIG: Single - A new note triggers the ramp only when no other\n";
		descriptionString += "notes are currently held down (only active in unison mode).\n";
		descriptionString += "MTRIG: Multiple - the ramp is triggered with every new note played.\n";
		descriptionString += "XTRIG: External - an external signal (e.g. a footswitch) triggers the ramp.\n";
		descriptionString += "GATEX: Gated External - an external signal triggers the ramp only when\n";
		descriptionString += "there are one or more notes being played.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::defaultControl_w);
		controlCenterPoints.add(Point<int>(i == 1 ?  GUI::rampControlsCol1_x :  GUI::rampControlsCol2_x, GUI::controlsRow2_y));
		dataByteIndices.add(i == 1 ? (uint16)75 : (uint16)77);
	}

	//======================================================

	identifiers.add("track_Input");
	exposedNames.add("Tracking Generator Input");
	paramNumbers.add((uint8)33);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToTrackingInputString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)20);
	defaultValues.add((uint8)9);
	descriptionString =  "Selects the modulation source which\n";
	descriptionString += "will be shaped by the tracking generator.";
	descriptions.add(descriptionString);
	controlWidths.add(94);
	controlCenterPoints.add(Point<int>(943, 165));
	dataByteIndices.add((uint16)68);

	identifiers.add("track_Point1");
	exposedNames.add("Track Point 1");
	paramNumbers.add((uint8)34);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Track Point 1\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 0.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::trackPointControls_w);
	controlCenterPoints.add(Point<int>( GUI::trackPoint1Control_x,  GUI::trackPointControls_y));
	dataByteIndices.add((uint16)69);

	identifiers.add("track_Point2");
	exposedNames.add("Track Point 2");
	paramNumbers.add((uint8)35);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)15);
	descriptionString =  "Track Point 2\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 15.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::trackPointControls_w);
	controlCenterPoints.add(Point<int>( GUI::trackPoint2Control_x,  GUI::trackPointControls_y));
	dataByteIndices.add((uint16)70);

	identifiers.add("track_Point3");
	exposedNames.add("Track Point 3");
	paramNumbers.add((uint8)36);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Track Point 3\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 31.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::trackPointControls_w);
	controlCenterPoints.add(Point<int>( GUI::trackPoint3Control_x,  GUI::trackPointControls_y));
	dataByteIndices.add((uint16)71);

	identifiers.add("track_Point4");
	exposedNames.add("Track Point 4");
	paramNumbers.add((uint8)37);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)47);
	descriptionString =  "Track Point 4\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 47.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::trackPointControls_w);
	controlCenterPoints.add(Point<int>( GUI::trackPoint4Control_x,  GUI::trackPointControls_y));
	dataByteIndices.add((uint16)72);

	identifiers.add("track_Point5");
	exposedNames.add("Track Point 5");
	paramNumbers.add((uint8)38);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)63);
	descriptionString =  "Track Point 5\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 63.";
	descriptions.add(descriptionString);
	controlWidths.add( GUI::trackPointControls_w);
	controlCenterPoints.add(Point<int>( GUI::trackPoint5Control_x,  GUI::trackPointControls_y));
	dataByteIndices.add((uint16)73);

	//======================================================

	for (uint8 i = 0; i != 3; ++i) {
		identifiers.add("env" + String(i + 1) + "_Delay");
		exposedNames.add("Envelope " + String(i + 1) + " Delay Time");
		paramNumbers.add(uint8(50 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add((uint8)0);
		descriptionString =  "Sets the length of the delay stage of\n";
		descriptionString += "envelope " + String(i + 1) + ", the wait after the envelope is\n";
		descriptionString += "triggered before the attack stage begins.\n";
		descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envShapeControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Delay_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow4_y));
		dataByteIndices.add(uint16(42 + i * 9));

		identifiers.add("env" + String(i + 1) + "_Attack");
		exposedNames.add("Envelope " + String(i + 1) + " Attack Time");
		paramNumbers.add(uint8(51 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add((uint8)0);
		descriptionString =  "Sets the length of the attack stage\n";
		descriptionString += "of envelope " + String(i + 1) + ", the time it takes to\n";
		descriptionString += "reach the maximum output level.\n";
		descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envShapeControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Attack_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow4_y));
		dataByteIndices.add(uint16(43 + i * 9));

		identifiers.add("env" + String(i + 1) + "_Decay");
		exposedNames.add("Envelope " + String(i + 1) + " Decay Time");
		paramNumbers.add(uint8(52 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(i == 2 ? (uint8)20 : (uint8)10);
		descriptionString =  "Sets the length of the decay stage of\n";
		descriptionString += "envelope " + String(i + 1) + ", the time it takes for the\n";
		descriptionString += "output to drop to the sustain level.\n";
		descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envShapeControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Decay_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow4_y));
		dataByteIndices.add(uint16(44 + i * 9));

		identifiers.add("env" + String(i + 1) + "_Sustain");
		exposedNames.add("Envelope " + String(i + 1) + " Sustain Level");
		paramNumbers.add(uint8(53 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(i == 2 ? (uint8)0 : (uint8)50);
		descriptionString =  "Sets the sustain level of envelope " + String(i + 1) + ". After the\n";
		descriptionString += "decay stage completes, output will remain at\n";
		descriptionString += "this level until the voice is gated off.\n";
		descriptionString += "Range: 0 (no output) to 63 (maximum).";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envShapeControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Sustain_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow4_y));
		dataByteIndices.add(uint16(45 + i * 9));

		identifiers.add("env" + String(i + 1) + "_Release");
		exposedNames.add("Envelope " + String(i + 1) + " Release Time");
		paramNumbers.add(uint8(54 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add(i == 2 ? (uint8)20 : (uint8)10);
		descriptionString = " Sets the length of the release stage\n";
		descriptionString += "of envelope " + String(i + 1) + ", the time it takes to drop\n";
		descriptionString += "from the sustain level to no output.\n";
		descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envShapeControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Release_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow4_y));
		dataByteIndices.add(uint16(46 + i * 9));

		identifiers.add("env" + String(i + 1) + "_Amplitude");
		exposedNames.add("Envelope " + String(i + 1) + " Amplitude");
		paramNumbers.add(uint8(55 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToUnsignedValueString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)63);
		defaultValues.add((uint8)40);
		descriptionString =  "Sets the maximum output level of envelope " + String(i + 1) + ", which determines\n";
		descriptionString += "the degree to which the envelope modulates its destination.\n";
		descriptionString += "Range: 0 (none) to 63 (maximum).";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Controls_x + i *  GUI::envSectionsHorizontalSpacing, GUI::envControlsRow1_y));
		dataByteIndices.add(uint16(47 + i * 9));

		identifiers.add("env" + String(i + 1) + "_Velo");
		exposedNames.add("Envelope " + String(i + 1) + " Velocity Amount");
		paramNumbers.add(uint8(56 + i * 10));
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::rotarySlider);
		converters.add(IntToSigned7bitValueString::get());
		rangeTypes.add(RangeType::signed7bitValue);
		maxValues.add((uint8)126);
		defaultValues.add((uint8)126);
		descriptionString =  "Sets whether and to what degree note\n";
		descriptionString += "velocity modulates envelope " + String(i + 1) + GUI::apostrophe + "s amplitude.\n";
		descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
		descriptionString += "Negative values invert the velocity response.\n";
		descriptionString += "NOTE: Negative values cannot be\n";
		descriptionString += "assigned to individual parameters via\n";
		descriptionString += "Quick Patch Edit. Use the PUSH button\n";
		descriptionString += "to send the entire patch instead.";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Controls_x + i *  GUI::envSectionsHorizontalSpacing, GUI::envControlsRow2_y));
		dataByteIndices.add(uint16(86 + i));

		identifiers.add("env" + String(i + 1) + "_TrigMode");
		exposedNames.add("Envelope " + String(i + 1) + " Trigger Mode");
		paramNumbers.add((uint8)57 + i * 10);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToEnvTrigModeString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)7);
		defaultValues.add((uint8)0);
		descriptionString =  "Selects what sort of trigger will start envelope " + String(i + 1) + GUI::apostrophe + "s cycle.\n";
		descriptionString += "STRIG: Single trigger (unison mode only) - the cycle will start for\n";
		descriptionString += "a voice only if it is not already playing. Legato playing will not\n";
		descriptionString += "re-trigger the cycle. If the envelope is re-triggered before its cycle\n";
		descriptionString += "completes, it will continue from the point it was at in the cycle.\n";
		descriptionString += "SRESET: Single trigger reset - like single trigger mode, except\n";
		descriptionString += "that if the envelope is re-triggered before its cycle completes,\n";
		descriptionString += "the envelope will reset to the start of the cycle.\n";
		descriptionString += "MTRIG: Multiple trigger - New notes will always re-trigger the envelope,\n";
		descriptionString += "and it will continue from the last point it was at in its cycle.\n";
		descriptionString += "MRESET: Multiple trigger reset - new notes will always re-trigger\n";
		descriptionString += "the envelope and reset it to the beginning of its cycle.\n";
		descriptionString += "The remaining modes behave like their counterparts above, but the trigger\n";
		descriptionString += "comes from a DC pulse (e.g. from a footswitch) sent into the PEDAL 2 jack:\n";
		descriptionString += "XTRIG: External single trigger; XRESET: External single trigger reset;\n";
		descriptionString += "XMTRIG: External multiple trigger; XMRST: External multiple trigger reset.";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Controls_x + i *  GUI::envSectionsHorizontalSpacing, GUI::envControlsRow3_y));
		dataByteIndices.add((uint16)41 + i * 9);

		identifiers.add("env" + String(i + 1) + "_Mode");
		exposedNames.add("Envelope " + String(i + 1) + " Mode");
		paramNumbers.add((uint8)58 + i * 10);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToEnvModeString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)3);
		defaultValues.add((uint8)0);
		descriptionString =  "Selects how envelope " + String(i + 1) + " completes its cycle when triggered.\n";
		descriptionString += "NORMAL: When a note is gated on and the envelope is triggered, the cycle\n";
		descriptionString += "will run through the delay, attack, and decay stages, then hold at the\n";
		descriptionString += "sustain level. Gating off the note will immediately trigger the release\n";
		descriptionString += "stage, even if the sustain stage has not yet been reached.\n";
		descriptionString += "DADR: Delay-Attack-Decay-Release - the release stage begins immediately\n";
		descriptionString += "after the decay stage, whether or not the note is still geted on. Gating off \n";
		descriptionString += "the note before the other stages complete will also start the release stage.\n";
		descriptionString += "FREE: Free run - the envelope will completely run through the delay, attack,\n";
		descriptionString += "decay, and release stages, whether or not the note is kept gated on.\n";
		descriptionString += "Keeping the note gated on will hold the sustain level normally.\n";
		descriptionString += "BOTH: Both DADR and free run - like free run mode, except the release stage\n";
		descriptionString += "begins immediately after the decay stage, even if the note is still gated on.";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Controls_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow4_y));
		dataByteIndices.add((uint16)49 + i * 9);

		identifiers.add("env" + String(i + 1) + "_LFO1Trig");
		exposedNames.add("Envelope " + String(i + 1) + " LFO 1 Trigger");
		paramNumbers.add((uint8)59 + i * 10);
		isQuickEditEnabled.add((bool)true);
		controlTypes.add(ControlType::comboBox);
		converters.add(IntToEnvLFO1TrigString::get());
		rangeTypes.add(RangeType::unsignedValue);
		maxValues.add((uint8)2);
		defaultValues.add((uint8)0);
		descriptionString =  "Selects whether and how envelope " + String(i + 1) + GUI::apostrophe + "s cycle is triggered by LFO 1.\n";
		descriptionString += "NORMAL: The envelope cycle is not triggered by LFO 1.\n";
		descriptionString += "G-LFO1: Gated LFO 1 trigger - LFO 1 will trigger the envelope cycle\n";
		descriptionString += "periodically only if one or more notes are currently gated on.\n";
		descriptionString += "LFO 1: The envelope cycle is triggered periodically by LFO 1.\n";
		descriptionString += "The point in LFO 1" + GUI::apostrophe + "s cycle which actually triggers the envelope\n";
		descriptionString += "cycle is determined by the LFO 1 Retrigger Point parameter above.";
		descriptions.add(descriptionString);
		controlWidths.add( GUI::envControls_w);
		controlCenterPoints.add(Point<int>(GUI::env1Controls_x + i *  GUI::envSectionsHorizontalSpacing,  GUI::envControlsRow5_y));
		dataByteIndices.add((uint16)48 + i * 9);
	}

}

InfoForExposedParameters& InfoForExposedParameters::get() noexcept {
	static InfoForExposedParameters exposedParamsInfo;
	return exposedParamsInfo;
}

int InfoForExposedParameters::paramOutOfRange() const noexcept {
	return identifiers.size();
}

Identifier InfoForExposedParameters::IDfor(uint8 paramIndex) const {
	return identifiers[paramIndex];
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) const {
	return exposedNames[paramIndex];
}

uint8 InfoForExposedParameters::paramNumberFor(uint8 paramIndex) const {
	return paramNumbers[paramIndex];
}

bool InfoForExposedParameters::isQuickEditable(uint8 paramIndex) const {
	return isQuickEditEnabled[paramIndex];
}

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) const {
	return controlTypes[paramIndex];
}

IntToContextualStringConverter* InfoForExposedParameters::converterFor(uint8 paramIndex) const {
	return converters[paramIndex];
}

RangeType InfoForExposedParameters::rangeTypeFor(uint8 paramIndex) const {
	return rangeTypes[paramIndex];
}

uint8 InfoForExposedParameters::maxValueFor(uint8 paramIndex) const {
	return maxValues[paramIndex];
}

uint8 InfoForExposedParameters::defaultValueFor(uint8 paramIndex) const {
	return defaultValues[paramIndex];
}

uint8 InfoForExposedParameters::numberOfStepsFor(uint8 paramIndex) const {
	return maxValues[paramIndex] + 1;
}

String InfoForExposedParameters::descriptionFor(uint8 paramIndex) const {
	return descriptions[paramIndex];
}

Point<int> InfoForExposedParameters::controlCenterPointFor(uint8 paramIndex) const {
	return controlCenterPoints[paramIndex];
}

int InfoForExposedParameters::controlWidthFor(uint8 paramIndex) const {
	return controlWidths[paramIndex];
}

uint8 InfoForExposedParameters::indexForParamID(const String& parameterID) const {
	return (uint8)identifiers.indexOf(Identifier(parameterID));
}

uint16 InfoForExposedParameters::dataByteIndexFor(uint8 paramIndex) const {
	return dataByteIndices[paramIndex];
}

