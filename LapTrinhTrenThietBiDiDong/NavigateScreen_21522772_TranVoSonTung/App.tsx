import React from 'react';
import {
  DarkTheme,
  DefaultTheme,
  NavigationContainer,
} from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import HomePage from './assets/pages/HomePage';
import FavouritePage from './assets/pages/FavouritePage';
import SettingPage from './assets/pages/SettingPage';
import MaterialIcons from 'react-native-vector-icons/MaterialCommunityIcons';
import { useState } from 'react';
import AsyncStorage from '@react-native-async-storage/async-storage';

const Tab = createBottomTabNavigator();
function App() {
  const [scheme, setScheme] = useState('light');

  return (
    <NavigationContainer>
      <Tab.Navigator>
        <Tab.Screen
          name="Home"
          component={HomePage}
          options={{
            tabBarLabel: 'Home',
            tabBarIcon: ({ color, size }) => (
              <MaterialIcons name="home" color={color} size={size} />
            ),
          }}
          listeners={({ navigation }) => ({
            tabPress: e => {
              e.preventDefault();
              navigation.navigate('Home', { scheme });
            },
          })}
        />
        <Tab.Screen
          name="Favourites"
          component={FavouritePage}
          options={{
            tabBarLabel: 'Favourites',
            tabBarIcon: ({ color, size }) => (
              <MaterialIcons name="bell" color={color} size={size} />
            ),
            tabBarBadge: 3,
          }}
          listeners={({ navigation }) => ({
            tabPress: e => {
              e.preventDefault();
              navigation.navigate('Favourites', { scheme });
            },
          })}
        />
        <Tab.Screen
          name="Settings"
          component={SettingPage}
          options={{
            tabBarLabel: 'Settings',
            tabBarIcon: ({ color, size }) => (
              <MaterialIcons name="settings" color={color} size={size} />
            ),
          }}
          listeners={({ navigation }) => ({
            tabPress: e => {
              e.preventDefault();
              navigation.navigate('Settings', { scheme, setScheme });
            },
          })}
        />
      </Tab.Navigator>
    </NavigationContainer>
  );
}

export default App;
