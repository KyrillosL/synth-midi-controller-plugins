#include "up_0_tree_VoiceTransmissionOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;

VoiceTransmissionOptions::VoiceTransmissionOptions() :
	voiceTransmissionOptionsTree{ ID::tree_VoiceTxOptions }
{
	setParamChangesShouldBeTransmitted(true);
	setVoiceTransmitTime(300);
}

const bool VoiceTransmissionOptions::paramChangesShouldBeTransmitted() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_TransmitParamChanges) == true;
}

void VoiceTransmissionOptions::setParamChangesShouldBeTransmitted(const bool shouldBeTransmitted) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_TransmitParamChanges, shouldBeTransmitted ? (bool)true : (bool)false, nullptr);
}

const int VoiceTransmissionOptions::voiceTransmitTime() {
	return (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time);
}

void VoiceTransmissionOptions::setVoiceTransmitTime(const int timeInMilliseconds) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, timeInMilliseconds, nullptr);
}

std::unique_ptr<XmlElement> VoiceTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> voiceTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_VoiceTxOptions) };
	if (voiceTransmissionOptionsTreeStateXml != nullptr) {
		voiceTransmissionOptionsTreeStateXml->setAttribute(ID::voiceTx_Time, voiceTransmitTime());
	}
	return voiceTransmissionOptionsTreeStateXml;
}

void VoiceTransmissionOptions::replaceState(const ValueTree& newState) {
	auto voiceTransmitTime{ newState.getProperty(ID::voiceTx_Time) };
	if (!voiceTransmitTime.isVoid())
		voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, voiceTransmitTime, nullptr);
}
