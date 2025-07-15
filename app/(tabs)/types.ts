import { AudioNode, BaseAudioContext } from "react-native-audio-api";
import { IAudioNode, IBaseAudioContext } from "react-native-audio-api/lib/typescript/interfaces";

interface IMyProcessorNode extends IAudioNode {
    gain: number;
}

export class MyProcessorNode extends AudioNode {
    gain: number;
    constructor(context: BaseAudioContext, node: IMyProcessorNode) {
        super(context, node);
        this.gain = 0.5;
    }
}

declare global {
    var createCustomProcessorNode: (context: IBaseAudioContext) => IMyProcessorNode;
}