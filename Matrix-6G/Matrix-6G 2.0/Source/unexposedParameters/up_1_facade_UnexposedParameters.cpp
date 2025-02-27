#include "up_1_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;

UnexposedParameters::UnexposedParameters() :
    globalOptions{ new GlobalOptions{} },
    outgoing_MIDI_Buffers{ new Outgoing_MIDI_Buffers{} },
    splitOptions{ new SplitOptions{} },
    splitsBank{ new SplitsBank{} },
    tooltipsOptions{ new TooltipsOptions{} },
    voicesBanks{ new VoicesBanks{} },
    voiceTransmissionOptions{ new VoiceTransmissionOptions{} }
{
}

GlobalOptions* UnexposedParameters::getGlobalOptions() {
    return globalOptions.get();
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::getBundledOutgoingBuffers() {
    return outgoing_MIDI_Buffers->getBundledOutgoingBuffers();
}

Outgoing_MIDI_Buffers* UnexposedParameters::getOutgoing_MIDI_Buffers() {
    return outgoing_MIDI_Buffers.get();
}

SplitOptions* UnexposedParameters::getSplitOptions() {
    return splitOptions.get();
}

SplitsBank* UnexposedParameters::getSplitsBank() {
    return splitsBank.get();
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
    return tooltipsOptions.get();
}

VoicesBanks* UnexposedParameters::getVoicesBanks() {
    return voicesBanks.get();
}

VoiceTransmissionOptions* UnexposedParameters::getVoiceTransmissionOptions() {
    return voiceTransmissionOptions.get();
}

std::unique_ptr<XmlElement> UnexposedParameters::getStateXml() {
    auto unexposedParamsStateXml{ std::make_unique<XmlElement>(ID::state_UnexposedParams) };

    auto splitOptionsStateXml{ splitOptions->getStateXml() };
    if (splitOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(splitOptionsStateXml.release());

    auto splitsBankStateXml{ splitsBank->getStateXml() };
    if (splitsBankStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(splitsBankStateXml.release());

    auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
    if (tooltipOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(tooltipOptionsStateXml.release());

    auto customVoicesBanksStateXml{ voicesBanks->getStateXml() };
    if (customVoicesBanksStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(customVoicesBanksStateXml.release());

    auto voiceTxOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
    if (voiceTxOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(voiceTxOptionsStateXml.release());

    return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
    if (newState.isValid()) {
        auto splitOptionsState{ newState.getChildWithName(ID::state_SplitOptions) };
        if (splitOptionsState.isValid())
            splitOptions->replaceState(splitOptionsState);

        auto splitsBankState{ newState.getChildWithName(ID::state_SplitsBank) };
        if (splitsBankState.isValid())
            splitsBank->replaceState(splitsBankState);

        auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipsOptions) };
        if (tooltipOptionsState.isValid())
            tooltipsOptions->replaceState(tooltipOptionsState);

        auto customVoicesBanksState{ newState.getChildWithName(ID::state_CustomVoicesBanks) };
        if (customVoicesBanksState.isValid())
            voicesBanks->replaceState(customVoicesBanksState);

        auto voiceTxOptionsState{ newState.getChildWithName(ID::state_VoiceTxOptions) };
        if (voiceTxOptionsState.isValid())
            voiceTransmissionOptions->replaceState(voiceTxOptionsState);
    }
}

UnexposedParameters::~UnexposedParameters() {
    splitOptions = nullptr;
    splitsBank = nullptr;
    tooltipsOptions = nullptr;
    voicesBanks = nullptr;
    voiceTransmissionOptions = nullptr;
}
