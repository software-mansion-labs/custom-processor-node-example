import React, { useCallback, useEffect, useState, FC, useRef } from 'react';
import { ActivityIndicator } from 'react-native';
import { AudioContext, AudioNode } from 'react-native-audio-api';
import { Container, Button } from '../components';
import AudioPlayer from './AudioPlayer';
import Turbo from '../../specs/NativeAudioProcessingModule';

const URL =
  'https://software-mansion.github.io/react-native-audio-api/audio/music/example-music-01.mp3';

const AudioFile: FC = () => {
  const [isPlaying, setIsPlaying] = useState(false);
  const [isLoading, setIsLoading] = useState(false);
  const [customProcessor, setCustomProcessor] = useState(false);
  const audioContextRef = useRef<AudioContext | null>(null);

  const togglePlayPause = async () => {
    if (isPlaying) {
      await AudioPlayer.pause();
    } else {
      await AudioPlayer.play(customProcessor);
    }

    setIsPlaying((prev) => !prev);
  };

  const fetchAudioBuffer = useCallback(async () => {
    setIsLoading(true);

    await AudioPlayer.loadBuffer(URL);
    if (Turbo) {
      if (global.createCustomProcessorNode == null) {
        console.log('Injecting custom processor node installer');
        Turbo.injectCustomProcessorInstaller();
      }
    } else {
      console.log('Turbo module is not available');
    }

    setIsLoading(false);
  }, []);

  const toggleCustomProcessor = () => { 
    setCustomProcessor((prev) => !prev);
  };
  
  useEffect(() => {
    if (!audioContextRef.current) {
      audioContextRef.current = new AudioContext();
    }
    fetchAudioBuffer();
  }, [fetchAudioBuffer]);

  return (
    <Container centered>
      {isLoading && <ActivityIndicator color="#FFFFFF" />}
      <Button
        title={isPlaying ? 'Stop' : 'Play'}
        onPress={togglePlayPause}
        disabled={isLoading}
      />
      <Button
        title={customProcessor ? "Remove custom processor" : "Apply custom processor"}
        onPress={toggleCustomProcessor}
        disabled={isLoading} />

    </Container>
  );
};

export default AudioFile;
