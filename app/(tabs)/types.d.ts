import { AudioNode } from "react-native-audio-api";
import { IBaseAudioContext } from "react-native-audio-api/lib/typescript/interfaces";

declare global {
    var createCustomProcessorNode: (context: IBaseAudioContext) => AudioNode;
}