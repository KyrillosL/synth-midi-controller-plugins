#include "build_MainWindowButtonDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;

String MainWindowButtonDescription::buildForActivateQuickEdit() {
    String descriptionString{ "" };
    descriptionString += "The Matrix must be set to Quick Patch Edit mode in\n";
    descriptionString += "order for it to respond to remote parameter changes.\n";
    descriptionString += "Click this button before making any edits in the GUI\n";
    descriptionString += "(the hardware" + GUI::apostrophe + "s front panel display should switch\n";
    descriptionString += "to PATCH EDIT). Shortcut key: CTRL+Q";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowGlobalParamsLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can edit the\n";
    descriptionString += GUI::openQuote + "master" + GUI::closeQuote + " options which apply\n";
    descriptionString += "to all patches. Shortcut key: CTRL+M";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowSplitsLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can create and store\n";
    descriptionString += (GUI::openQuote + "splits," + GUI::closeQuote + " which allow you to play two voices\n");
    descriptionString += "at once with a single keyboard controller.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowVoicesBanksLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can manage\n";
    descriptionString += "the patch presets storage banks.\n";
    descriptionString += "Shortcut key: CTRL+P";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPull() {
    String descriptionString{ "" };
    descriptionString += "Pull the data from the selected patch storage slot in the Matrix-6R\n";
    descriptionString += "hardware and apply it to the plugin GUI. Shortcut key: CTRL+[";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPush() {
    String descriptionString{ "" };
    descriptionString += "Sends a dump of the current patch data to the hard-\n";
    descriptionString += "ware storage slot specified by the patch number\n";
    descriptionString += "control to the right, NOTE: This overwrites the\n";
    descriptionString += "data that is currently stored in the slot and\n";
    descriptionString += "cannot be undone. Shortcut key: CTRL+]";
    return descriptionString;
}
