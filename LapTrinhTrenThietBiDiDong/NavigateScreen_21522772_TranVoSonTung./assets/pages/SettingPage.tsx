import React from 'react';
import { useState } from 'react';
import CheckBox from '@react-native-community/checkbox';
import { AsyncStorage } from 'react-native';
import { StyleSheet, Text, View } from 'react-native';

function SettingPage() {
  const [toggleDarkTheme, setToggleDarkTheme] = useState(true);
  const [toggleLightTheme, setToggleLightTheme] = useState(false);

  const storeTheme = async (theme: string) => {
    try {
      await AsyncStorage.setItem('StiluxAppTheme', theme);
    } catch (error) {
      console.log(error);
    }
  };
  function handleToggleCheckBox() {
    if (toggleDarkTheme) {
      setToggleDarkTheme(false);
      setToggleLightTheme(true);
      storeTheme('light');
    } else {
      setToggleDarkTheme(true);
      setToggleLightTheme(false);
      storeTheme('dark');
    }
  }

  return (
    <View>
      <View style={styles.themeWrapper}>
        <Text style={styles.text}>Dark Theme</Text>
        <CheckBox
          disabled={false}
          value={toggleDarkTheme}
          onValueChange={() => handleToggleCheckBox()}
        />
      </View>
      <View style={styles.themeWrapper}>
        <Text style={styles.text}>Light Theme</Text>
        <CheckBox
          disabled={false}
          value={toggleLightTheme}
          onValueChange={() => handleToggleCheckBox()}
        />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  homePage: {
    height: '100%',
    width: '100%',
    paddingBottom: 20,
  },
  themeWrapper: {
    display: 'flex',
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    paddingTop: 10,
    paddingBottom: 10,
    paddingLeft: 15,
    paddingRight: 15,
    marginBottom: 10,
    backgroundColor: '#4fb5c9',
  },
  text: {
    fontSize: 20,
    color: '#333',
  },
});

export default SettingPage;
