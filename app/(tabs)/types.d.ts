import { IBaseAudioContext, IAudioNode } from 'react-native-audio-api/lib/typescript/interfaces';

declare global {
    var createCustomProcessorNode: (context: IBaseAudioContext) => IAudioNode;
}