import React from 'react';
import { useState } from 'react';
import { StyleSheet, Text, TextInput, View } from 'react-native';

function LoginScreen({ navigation }: { navigation: object }): JSX.Element {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');

  function handleLogin() {
    navigation?.navigate('Home');
  }

  return (
    <View style={styles.loginPage}>
      <Text style={styles.headerLogin}>Login</Text>
      <TextInput
        onChangeText={newUsername => setUsername(newUsername)}
        placeholder="Username"
        style={styles.textInput}
      />
      <TextInput
        onChangeText={newPass => setPassword(newPass)}
        placeholder="Password"
        style={styles.textInput}
      />
      <Text onPress={handleLogin} style={[styles.btn, styles.signInBtn]}>
        Sign in
      </Text>
    </View>
  );
}

const styles = StyleSheet.create({
  loginPage: {
    display: 'flex',
    alignItems: 'center',
    width: '100%',
    height: '100%',
  },
  headerLogin: {
    fontSize: 40,
    color: '#7c93cf',
  },
  textInput: {
    alignSelf: 'center',
    width: '90%',
    height: 50,
    borderWidth: 1,
    borderRadius: 5,
    paddingLeft: 15,
    fontSize: 16,
    marginTop: 10,
  },
  btn: {
    textAlign: 'center',
    fontSize: 24,
    color: 'white',
    backgroundColor: '#7c93cf',
    borderRadius: 5,
    padding: 10,
  },
  signInBtn: {
    width: '90%',
    marginTop: 10,
  },
});

export default LoginScreen;
