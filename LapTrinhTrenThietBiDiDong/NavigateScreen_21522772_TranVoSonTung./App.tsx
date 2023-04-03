import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import DetailPage from './assets/pages/DetailPage';
import HomePage from './assets/pages/HomePage';
import Ionicons from 'react-native-vector-icons/Ionicons';
import FavouritePage from './assets/pages/FavouritePage';
import SettingPage from './assets/pages/SettingPage'

const Tab = createBottomTabNavigator();

function App() {
  return (
    <NavigationContainer>
      <Tab.Navigator>
        <Tab.Screen name="Home" component={HomePage} />
        <Tab.Screen name="Favorite" component={FavouritePage} />
        <Tab.Screen name="Settings" component={SettingPage} />
      </Tab.Navigator>
    </NavigationContainer>
  );
}

export default App;
