import React from 'react';
import TodoCard from '../components/TodoCard';
import {
  FlatList,
  Image,
  Pressable,
  ScrollView,
  StyleSheet,
  View,
} from 'react-native';
import { useSelector } from 'react-redux';
import Job from '../src/types/job';
import { useEffect, useState } from 'react';

function HomeScreen({ navigation }: { navigation: object }): JSX.Element {
  function handleAddTodo(): void {
    navigation?.navigate('Detail');
  }
  const currentJobs = useSelector(state => state?.jobReducer?.jobs);
  console.log(currentJobs);

  return (
    <View style={[styles.homePage]}>
      <View>
        <ScrollView style={styles.scrollView}>
          <View style={styles.container}>
            {currentJobs?.map((job: Job, index: number) => (
              <TodoCard
                key={index}
                title={job?.title}
                description={job?.description}
                date={job?.date.toString()}
                overrideStyle={styles.todoCard}
              />
            ))}
          </View>
        </ScrollView>
      </View>
      <Pressable onPress={handleAddTodo}>
        <Image
          style={styles.addBtn}
          source={{
            uri: 'https://w7.pngwing.com/pngs/535/334/png-transparent-computer-icons-add-button-logo-number-add-button-thumbnail.png',
          }}
        />
      </Pressable>
    </View>
  );
}

const styles = StyleSheet.create({
  addBtn: {
    width: 50,
    height: 50,
    position: 'absolute',
    bottom: 30,
    right: 30,
  },
  homePage: {
    height: '100%',
    width: '100%',
    position: 'relative',
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
    width: '100%',
    height: '100%',
  },
  todoCard: {
    width: '95%',
    paddingTop: 20,
    paddingBottom: 20,
    borderRadius: 10,
    margin: 20,
  },
});

export default HomeScreen;
