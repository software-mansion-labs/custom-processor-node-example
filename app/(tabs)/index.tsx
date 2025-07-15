import React, { useCallback, useEffect, useState, FC, useRef } from 'react';
import { ActivityIndicator } from 'react-native';
import { Container, Button } from '../components';
import AudioPlayer from './AudioPlayer';
import Turbo from '../../specs/NativeAudioProcessingModule';
import Slider from '@react-native-community/slider';

const URL =
  'https://software-mansion.github.io/react-native-audio-api/audio/music/example-music-01.mp3';

const AudioFile: FC = () => {
  const [isPlaying, setIsPlaying] = useState(false);
  const [isLoading, setIsLoading] = useState(false);
  const [customProcessor, setCustomProcessor] = useState(false);
  const [gain, setGain] = useState(0.1);

  const togglePlayPause = async () => {
    if (isPlaying) {
      await AudioPlayer.pause();
    } else {
      await AudioPlayer.play(customProcessor);
    }

    setIsPlaying((prev) => !prev);
  };

  useEffect(() => {
    AudioPlayer.modifyGain(gain);
  }, [gain]);

  const fetchAudioBuffer = useCallback(async () => {
    setIsLoading(true);

    await AudioPlayer.loadBuffer(URL);
    if (Turbo) {
      if (global.createCustomProcessorNode == null) {
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
      <Slider
        style={{ width: 300, height: 40 }}
        minimumValue={0}
        maximumValue={1}
        step={0.1}
        value={gain}
        onValueChange={setGain}
        minimumTrackTintColor="#1EB1FC"
        maximumTrackTintColor="#8E8E93"
        thumbTintColor="#1EB1FC"
      />
      <Button
        title={customProcessor ? "Remove custom processor" : "Apply custom processor"}
        onPress={toggleCustomProcessor}
        disabled={isLoading} />

    </Container>
  );
};

export default AudioFile;
