#pragma once

#include <JuceHeader.h>

class TooltipsOptions;

class GUI_Layer_FileOverwriteDialog :
	public Component
{
	TextButton btn_Esc;
	TextButton btn_OK;

public:
	GUI_Layer_FileOverwriteDialog() = delete;

	explicit GUI_Layer_FileOverwriteDialog(TooltipsOptions* tooltips);
	void addListenerToButtons(Button::Listener* listener);
	void removeListenerFromButtons(Button::Listener* listener);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FileOverwriteDialog)
};