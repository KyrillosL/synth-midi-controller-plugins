#pragma once

#include <JuceHeader.h>

#include "../params/params_UnexposedParameters_Facade.h"



// Overrides the mouseWheelMove() operation so that each wheel move event
// increments/decrements the slider's value by a single interval (step).
// Calls to beginNewTransaction() in the UndoManager are also added, so 
// that wheel moves which aren't performed in rapid succession on a single
// Slider instance are logged as discrete events for undo/redo.
class SliderWithMouseWheelMod : public Slider
{
	UnexposedParameters* unexposedParams;

public:
	SliderWithMouseWheelMod() = delete;

	explicit SliderWithMouseWheelMod(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& /*event*/, const MouseWheelDetails& wheel) override;
};




// Like SliderWithMouseWheelMod, but also modifies mouseWheelMove()
// so that the slider is incremented by 12 (one octave) when the 
// SHIFT key is being held down. 
class SliderWithMouseWheelModForPitch : public Slider
{
	UnexposedParameters* unexposedParams;

public:
	SliderWithMouseWheelModForPitch() = delete;

	explicit SliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;
};




// Like SliderWithMouseWheelMod, but also modifies mouseWheelMove() so that
// the slider is incremented by 10 when the SHIFT key is being held down. 
class SliderWithMouseWheelModForVoiceNumber : public Slider
{
	UnexposedParameters* unexposedParams;

public:
	SliderWithMouseWheelModForVoiceNumber() = delete;

	explicit SliderWithMouseWheelModForVoiceNumber(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;
};




class RotarySliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	RotarySliderWithMouseWheelMod() = delete;

	explicit RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParams);
};




class RotarySliderWithMouseWheelModForPitch : public SliderWithMouseWheelModForPitch
{
public:
	RotarySliderWithMouseWheelModForPitch() = delete;

	explicit RotarySliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams);
};




class RotarySliderWithMouseWheelModForVoiceNumber : public SliderWithMouseWheelModForVoiceNumber
{
public:
	RotarySliderWithMouseWheelModForVoiceNumber() = delete;

	explicit RotarySliderWithMouseWheelModForVoiceNumber(UnexposedParameters* unexposedParams);
};




class LinearSliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	LinearSliderWithMouseWheelMod() = delete;

	explicit LinearSliderWithMouseWheelMod(UnexposedParameters* unexposedParams);
};
