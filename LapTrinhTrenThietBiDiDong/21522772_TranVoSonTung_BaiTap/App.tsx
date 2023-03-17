/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 */

import React from 'react';
import { useState } from 'react';
import type { PropsWithChildren } from 'react';
import {
  SafeAreaView,
  StyleSheet,
  Text,
  TextInput,
  Button,
  View,
} from 'react-native';

function Login(): JSX.Element {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [status, setStatus] = useState('');

  function handleLogin() {
    if (username === 'abc' && password === '1234') {
      setStatus('Login Success');
      setUsername('');
      setPassword('');
    }
  }

  return (
    <View style={styles.sectionContainer}>
      <Text style={styles.sectionTitle}>Login</Text>
      <TextInput onChangeText={newUsername => setUsername(newUsername)} placeholder="Username" style={styles.textInput} />
      <TextInput onChangeText={newPass => setPassword(newPass)} placeholder="Password" style={styles.textInput} />
      <Text style={styles.status}>{status}</Text>
      <Button title="Login" onPress={() => handleLogin()} />
    </View>
  );
}

function App(): JSX.Element {
  return (
    <SafeAreaView>
      <Login />
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  sectionContainer: {
    marginTop: 32,
    paddingHorizontal: 24,
    alignItems: 'center',
    width: '100%',
  },
  status: {
    color: 'red',
    fontSize: 20,
    marginTop: 10,
    marginBottom: 10,
  },
  textInput: {
    width: '100%',
    height: 40,
    borderColor: 'gray',
    borderWidth: 1,
    marginTop: 10,
    marginBottom: 10,
    placeholderTextColor: 'gray',
    paddingLeft: 10,
  },
  button: {
    width: '100%',
    height: 40,
    borderColor: 'gray',
    borderWidth: 1,
  },
  sectionTitle: {
    fontSize: 60,
    fontWeight: '600',
  },
  sectionDescription: {
    marginTop: 8,
    fontSize: 18,
    fontWeight: '400',
  },
  highlight: {
    fontWeight: '700',
  },
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});

export default App;
