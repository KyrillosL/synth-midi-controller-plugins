#pragma once

#include <JuceHeader.h>

struct FontBuilder {
	static Font createFontFromTypeface_Size_Kerning(Typeface::Ptr typeface, float size, float kerning) {
		Font font{ typeface };
		font.setSizeAndStyle(size, font.getTypefaceStyle(), 1.0f, kerning);
		return font;
	}
};

namespace Matrix_6G_Constants
{
	namespace GUI
	{
		const Typeface::Ptr Swiss721_Bd{ Typeface::createSystemTypefaceFor(BinaryData::SWISSB_TTF, BinaryData::SWISSB_TTFSize) };
		const Typeface::Ptr Swiss721_CndLt{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };

		const Font font_BrowserText{ FontBuilder::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 16.0f, 0.0f) };
		const Font font_LabelEditors{ FontBuilder::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 16.0f, 0.0f) };
		const Font font_ProgressBar{ FontBuilder::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 14.0f, 0.0f) };
		const Font font_VoiceAndSplitSlotRadioButtons{ FontBuilder::createFontFromTypeface_Size_Kerning(Swiss721_CndLt, 13.0f, 0.0f) };
		const Font font_Tooltips{ FontBuilder::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 13.0f, 0.0f) };

		const String allowed_ASCII_Characters{ "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?<>;:.,-+*/=()'\"&%$#!_^\\|[" };
		const String apostrophe{ CharPointer_UTF8("\xe2\x80\x99") };
		const String openQuote{ CharPointer_UTF8("\xe2\x80\x9c") };
		const String closeQuote{ CharPointer_UTF8("\xe2\x80\x9d") };
	}
}