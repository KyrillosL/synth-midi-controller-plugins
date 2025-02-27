#include "imEx_3_gui_layer_Export_Voice.h"

#include "imEx_0_gui_layer_FileOverwriteDialog.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_Export_Voice::GUI_Layer_Export_Voice(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::exportVoice, bank, voiceSlots, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() }
{
	if (tooltips->shouldShowDescription()) {
		btn_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		btn_Cancel.setTooltip("Click to cancel the file export.");
		btn_Proceed.setTooltip("Click to export the selected patch" + GUI::apostrophe + "s\ndata to the specified file.");
	}
}

void GUI_Layer_Export_Voice::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ExportVoice_png, BinaryData::lbl_ExportVoice_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::bounds_ImportExport.getX() + border_w, GUI::bounds_ImportExport.getY() + border_w);
}

void GUI_Layer_Export_Voice::proceedButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile())
		showFileOverwriteDialog();
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeVoiceDataIntoFile(fileToWriteTo);
	}
}

void GUI_Layer_Export_Voice::showFileOverwriteDialog() {
	fileOverwriteDialog.reset(new GUI_Layer_FileOverwriteDialog(tooltips));
	fileOverwriteDialog->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteDialog.get());
	fileOverwriteDialog->setBounds(getLocalBounds());
	fileOverwriteDialog->grabKeyboardFocus();
}

void GUI_Layer_Export_Voice::buttonClicked(Button* button) {
	if (fileOverwriteDialog != nullptr) {
		if (button->getComponentID() == ID::btn_Cancel_FileOverwrite.toString()) {
			grabKeyboardFocus();
			fileOverwriteDialog->setVisible(false);
		}
		if (button->getComponentID() == ID::btn_Write_OverFile.toString()) {
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeVoiceDataIntoFile(selectedFile);
			fileOverwriteDialog->setVisible(false);
			hideThisLayer();
		}
	}
}

void GUI_Layer_Export_Voice::writeVoiceDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto slot{ voiceSlots->selectedSlot };
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slot) };
		outStream.writeText(voiceDataHexString, false, false, nullptr);
		hideThisLayer();
	}
}

GUI_Layer_Export_Voice::~GUI_Layer_Export_Voice() {
	if (fileOverwriteDialog != nullptr)
		fileOverwriteDialog->removeListenerFromButtons(this);
	fileOverwriteDialog = nullptr;
}
