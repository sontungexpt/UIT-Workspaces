import React from 'react';
import ClassCard from '../components/ClassCard';
import { StyleSheet, View, ScrollView } from 'react-native';

function HomeScreen({ navigation }: { navigation: object }): JSX.Element {
  function handlePressClassCard(classId: string): void {
    navigation?.navigate('Detail', {
      id: classId,
    });
  }

  return (
    <View style={[styles.homePage]}>
      <ScrollView style={styles.scrollView}>
        <View style={styles.container}>
          <ClassCard
            id="1"
            name="Class 1"
            overrideStyle={styles.classCard}
            onPress={() => handlePressClassCard('1')}
          />
        </View>
      </ScrollView>
    </View>
  );
}

const styles = StyleSheet.create({
  homePage: {
    display: 'flex',
    height: '100%',
    width: '100%',
    paddingBottom: 20,
    alignItems: 'center',
    justifyContent: 'center',
  },
  scrollView: {
    width: '100%',
    height: '100%',
  },
  container: {
    display: 'flex',
    alignItems: 'center',
    flexWrap: 'wrap',
    flexDirection: 'row',
    justifyContent: 'space-around',
    paddingBottom: 0,
  },
  classCard: {
    width: '95%',
    padding: 10,
    borderRadius: 10,
    margin: 20,
  },
});

export default HomeScreen;
