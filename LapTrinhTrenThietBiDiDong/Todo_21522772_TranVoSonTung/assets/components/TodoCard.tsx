import React from 'react';
import { Pressable, StyleSheet, Text, View } from 'react-native';

function TodoCard({
  title = 'No name',
  description = 'No description',
  date = 'No date',
  overrideStyle = {},
  onPress,
}: {
  title?: string;
  description?: string;
  date?: string;
  overrideStyle?: object;
  onPress?: () => void;
}): JSX.Element {
  return (
    <View style={[styles.todoCard, overrideStyle]}>
      <Pressable onPress={onPress} style={styles.container}>
        <View>
          <Text style={styles.date}>Date: {date}</Text>
          <Text style={styles.title}>Title: {title}</Text>
          <Text style={styles.description}>Description: {description}</Text>
        </View>
      </Pressable>
    </View>
  );
}

const styles = StyleSheet.create({
  todoCard: {
    display: 'flex',
    flexDirection: 'column',

    marginTop: 15,
    position: 'relative',

    backgroundColor: '#92ccff',

    borderRadius: 10,
  },
  container: {
    paddingLeft: 15,
    position: 'relative',
  },
  date: {
    fontSize: 22,
  },
  title: {
    fontSize: 22,
  },
  description: {
    fontSize: 22,
  },
});

export default TodoCard;
