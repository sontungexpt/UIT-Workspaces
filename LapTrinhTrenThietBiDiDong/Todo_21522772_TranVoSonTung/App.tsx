/* eslint-disable prettier/prettier */
import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import HomeScreen from './assets/screens/HomeScreen';
import DetailScreen from './assets/screens/DetailScreen';
import { Provider } from 'react-redux';
import allReducers from './assets/src/reducers';
import { legacy_createStore as createStore} from 'redux';

const store = createStore(allReducers);

const Stack = createNativeStackNavigator();

function App() {
  return (
    <Provider store={store}>
      <NavigationContainer>
        <Stack.Navigator initialRouteName="LoginScreen">
          <Stack.Screen name="Home" component={HomeScreen} />
          <Stack.Screen name="Detail" component={DetailScreen} />
        </Stack.Navigator>
      </NavigationContainer>
    </Provider>
  );
}
export default App;
