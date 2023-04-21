import React from 'react';
import { Pressable, StyleSheet, Text, View } from 'react-native';

function ClassCard({
  id = 'No id',
  name = 'No name',
  description = 'No description',
  studentCount = 0,
  overrideStyle = {},
  onPress,
}: {
  id?: string;
  name?: string;
  description?: string;
  studentCount?: number;
  overrideStyle?: object;
  onPress?: () => void;
}): JSX.Element {
  return (
    <View style={[styles.classCard, overrideStyle]}>
      <Pressable onPress={onPress} style={styles.container}>
        <Text style={styles.studentCount}>
          Number of students: {studentCount}
        </Text>
        <Text style={styles.classId}>Class Id: {id}</Text>
        <Text style={styles.className}>Class Name: {name}</Text>
        <Text style={styles.description}>Description: {description}</Text>
      </Pressable>
    </View>
  );
}

const styles = StyleSheet.create({
  classCard: {
    display: 'flex',
    flexDirection: 'column',
    backgroundColor: '#92ccff',
    borderRadius: 10,
    position: 'relative',
  },
  container: {
    paddingTop: 40,
    paddingBottom: 10,
    paddingLeft: 15,
    position: 'relative',
  },
  className: {
    fontSize: 22,
  },
  classId: {
    fontSize: 22,
  },
  description: {
    fontSize: 22,
  },
  studentCount: {
    fontSize: 14,
    position: 'absolute',
    top: 1,
    right: 1,
  },
});

export default ClassCard;
