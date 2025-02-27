#include "params_VoiceTransmissionOptions.h"

#include "params_Identifiers.h"



VoiceTransmissionOptions::VoiceTransmissionOptions() :
	voiceTransmissionOptionsTree{ ID::voiceTx_Options }
{
	fillVoiceTransmissionOptionsTreeWithProperties();
}

void VoiceTransmissionOptions::fillVoiceTransmissionOptionsTreeWithProperties() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankA, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankB, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, 300, nullptr);
}

bool VoiceTransmissionOptions::incomingVoiceShouldBeSavedInCustomBankA() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankA);
}

bool VoiceTransmissionOptions::incomingVoiceShouldBeSavedInCustomBankB() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankB);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldBeSavedInCustomBankA() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankA, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldBeSavedInCustomBankB() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankB, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldNotBeSavedInCustomBank() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankA, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInCustomBankB, (bool)false, nullptr);
}

bool VoiceTransmissionOptions::paramChangeEchoesAreNotBlocked() {
	return !(bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_ParamChangeEchoesAreBlocked);
}

void VoiceTransmissionOptions::setParamChangeEchoesAreBlocked() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setParamChangeEchoesAreNotBlocked() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)false, nullptr);
}

const int VoiceTransmissionOptions::voiceTransmitTime() {
	return (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time);
}

void VoiceTransmissionOptions::setVoiceTransmitTime(int timeInMilliseconds) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, timeInMilliseconds, nullptr);
}

XmlElement* VoiceTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> voiceTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_VoiceTransmissionOptions) };
	auto voiceTransmitTime{ (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time) };
	voiceTransmissionOptionsTreeStateXml->setAttribute(ID::voiceTx_Time, voiceTransmitTime);
	return voiceTransmissionOptionsTreeStateXml.release();
}

void VoiceTransmissionOptions::replaceState(const ValueTree& newState) {
	auto voiceTransmitTime{ newState.getProperty(ID::voiceTx_Time) };
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, voiceTransmitTime, nullptr);
}
