import React from 'react';
import { useState, useEffect } from 'react';
import CheckBox from '@react-native-community/checkbox';
import { Alert, StyleSheet, Text, View } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';

function SettingPage({ route }: { route: any }) {
  const { setScheme } = route.params;
  // const [theme, setTheme] = useState(scheme);
  const [theme, setTheme] = useState(() => {
    let defaultTheme = 'light';
    const getTheme = async () => {
      try {
        const themeSaved = await AsyncStorage.getItem('31_3_theme');
        const currentTheme = themeSaved ? JSON.parse(themeSaved) : 'light';
        return currentTheme;
      } catch (error) {
        console.log(error);
      }
    };
    getTheme().then(res => {
      if (res !== 'light' && res !== 'dark') {
        defaultTheme = 'light';
        return 'light';
      }
      defaultTheme = res;
      return res;
    });
    return defaultTheme;
  });

  const storeTheme = async (themeToStore: string) => {
    try {
      await AsyncStorage.setItem('31_3_theme', JSON.stringify(themeToStore));
    } catch (e) {
      Alert.alert('Error', 'Something went wrong');
    }
  };

  function handleToggleTheme() {
    setTheme(theme === 'light' ? 'dark' : 'light');
  }

  useEffect(() => {
    setScheme(theme);
    storeTheme(theme);
  }, [theme]);

  return (
    <View style={[styles.container, theme === 'dark' && styles.darkTheme]}>
      <View style={styles.themeWrapper}>
        <Text style={styles.text}>Dark Theme</Text>
        <CheckBox
          disabled={false}
          value={theme === 'dark'}
          onValueChange={() => handleToggleTheme()}
        />
      </View>
      <View style={styles.themeWrapper}>
        <Text style={styles.text}>Light Theme</Text>
        <CheckBox
          disabled={false}
          value={theme === 'light'}
          onValueChange={() => handleToggleTheme()}
        />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    height: '100%',
    width: '100%',
    paddingBottom: 20,
  },
  darkTheme: {
    backgroundColor: '#999',
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
